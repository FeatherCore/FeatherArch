# FeatherArch Build Script for PowerShell
# Usage: .\build.ps1 -Target cm4 -CC clang -AR llvm-ar -CFLAGS "..."

param(
    [Parameter(Mandatory=$true)]
    [ValidateSet("cm4", "cm7", "cm33", "cm55", "cm85")]
    [string]$Target,
    
    [Parameter(Mandatory=$true)]
    [string]$CC,
    
    [Parameter(Mandatory=$true)]
    [string]$AR,
    
    [Parameter(Mandatory=$true)]
    [string]$CFLAGS,
    
    [Parameter(Mandatory=$false)]
    [string]$BUILD_DIR = "build",
    
    [Parameter(Mandatory=$false)]
    [string]$INCLUDES = ""
)

# Create build directory if it doesn't exist
if (-not (Test-Path $BUILD_DIR)) {
    New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null
}

# Build
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "Building FeatherArch for target: $Target" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan
Write-Host "CC: $CC" -ForegroundColor Gray
Write-Host "AR: $AR" -ForegroundColor Gray
Write-Host "CFLAGS: $CFLAGS" -ForegroundColor Gray
Write-Host "BUILD_DIR: $BUILD_DIR" -ForegroundColor Gray
Write-Host ""

# Create a temporary ninja file with substituted variables
$ninjaTemplate = Get-Content -Raw -Path "build.ninja"
$ninjaContent = $ninjaTemplate `
    -replace '\$ENV\{TARGET\}', $Target `
    -replace '\$ENV\{CC\}', $CC `
    -replace '\$ENV\{AR\}', $AR `
    -replace '\$ENV\{CFLAGS\}', $CFLAGS `
    -replace '\$ENV\{BUILD_DIR\}', $BUILD_DIR `
    -replace '\$ENV\{INCLUDES\}', $INCLUDES

$tempNinjaFile = "$BUILD_DIR/build_$Target.ninja"
$ninjaContent | Set-Content -Path $tempNinjaFile

# Run ninja with the temporary file
& ninja -f $tempNinjaFile $Target

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "==========================================" -ForegroundColor Green
    Write-Host "Build successful!" -ForegroundColor Green
    Write-Host "Output: $BUILD_DIR/libfeatherarch_$Target.a" -ForegroundColor Green
    Write-Host "==========================================" -ForegroundColor Green
} else {
    Write-Host ""
    Write-Host "==========================================" -ForegroundColor Red
    Write-Host "Build failed!" -ForegroundColor Red
    Write-Host "==========================================" -ForegroundColor Red
    exit 1
}
