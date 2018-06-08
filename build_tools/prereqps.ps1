$ProjectRoot = $PSScriptRoot + "/.."

function Split-Path-Elements([String]$path, $count) {
    $parts = $path.Split("/")
    $cutparts = $parts[$count..($parts.Count-1)]
    $newpath = $cutparts -join '/'
    return $newpath
}

# Create expected folder structure
if (-not (Test-Path ($ProjectRoot + "/pkgs")))
{
    mkdir ($ProjectRoot + "/pkgs")
}

if (-not (Test-Path ($ProjectRoot + "/tmp")))
{
    mkdir ($ProjectRoot + "/tmp")
}

# Cloning dependencies
pushd ($ProjectRoot + "/pkgs")
if (-not (Test-Path ($ProjectRoot + "/pkgs/imgui")))
{
    echo "Cloning ImGUI"
    git clone https://github.com/ocornut/imgui.git
}
if (-not (Test-Path ($ProjectRoot + "/pkgs/imgui-sfml")))
{
    echo "Cloning ImGUI-SFML"
    git clone https://github.com/eliasdaler/imgui-sfml.git
}
if (-not (Test-Path ($ProjectRoot + "/pkgs/entityx")))
{
    echo "Cloning EntityX"
    git clone https://github.com/alecthomas/entityx.git
}
if (-not (Test-Path ($ProjectRoot + "/pkgs/json")))
{
    echo "Cloning nlohmann::json"
    git clone https://github.com/nlohmann/json.git
}
popd

# Preparation for Package downloads
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
Add-Type -Assembly System.IO.Compression.FileSystem

# Downloading packages
if (-not (Test-Path ($ProjectRoot + "/pkgs/include/GLFW")))
{
    echo "Downloading GLFW"
    wget "https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.bin.WIN64.zip" -OutFile ($ProjectRoot + "/tmp/glfw.zip")

    echo "Unpacking GLFW"
    $zip = [IO.Compression.ZipFile]::OpenRead($ProjectRoot + "/tmp/glfw.zip")
    $zip.Entries | where {($_.FullName -like '*include*') -or ($_.FullName -like '*lib-mingw-w64*')} | 
        foreach {
            $TargetFilePath = $ProjectRoot + "/pkgs/" + (Split-Path-Elements $_ 1)
            $TargetDirectoryPath = Split-Path -Path $TargetFilePath -Parent
            if (-not (Test-Path ($TargetDirectoryPath)))
            {
                New-Item -ItemType Directory -Force -Path $TargetDirectoryPath | Out-Null
            }
            if (-not [string]::IsNullOrEmpty($_.Name)) {
                [System.IO.Compression.ZipFileExtensions]::ExtractToFile($_, $TargetFilePath, $true)
            }
        }
    $zip.Dispose()
}

if (-not (Test-Path ($ProjectRoot + "/pkgs/include/SFML")))
{
    echo "Downloading SFML"
    [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
    wget "https://www.sfml-dev.org/files/SFML-2.5.0-windows-gcc-7.3.0-mingw-64-bit.zip" -OutFile ($ProjectRoot + "/tmp/SFML-2.5.0.zip")

    echo "Unpacking SFML"
    $zip = [IO.Compression.ZipFile]::OpenRead($ProjectRoot + "/tmp/SFML-2.5.0.zip")
    $zip.Entries |
        foreach {
            $TargetFilePath = $ProjectRoot + "/pkgs/" + (Split-Path-Elements $_ 1)
            $TargetDirectoryPath = Split-Path -Path $TargetFilePath -Parent
            if (-not (Test-Path ($TargetDirectoryPath)))
            {
                New-Item -ItemType Directory -Force -Path $TargetDirectoryPath | Out-Null
            }
            if (-not [string]::IsNullOrEmpty($_.Name)) {
                [System.IO.Compression.ZipFileExtensions]::ExtractToFile($_, $TargetFilePath, $true)
            }                
        }
    $zip.Dispose()
}