$ProjectRoot = $PSScriptRoot + "/.."

function Split-Path-Elements([String]$path, $count) {
    $parts = $path.Split("/")
    $cutparts = $parts[$count..($parts.Count-1)]
    $newpath = $cutparts -join '/'
    return $newpath
}

if (-not (Test-Path ($ProjectRoot + "/tmp/imgui")))
{
    pushd ($ProjectRoot + "/tmp")

    git clone https://github.com/ocornut/imgui.git
}

if (-not (Test-Path ($ProjectRoot + "/pkgs/include/GLFW")))
{
    echo "Extracting GLFW libraries"
    [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
    wget "https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.bin.WIN64.zip" -OutFile ($ProjectRoot + "/tmp/glfw.zip")

    Add-Type -Assembly System.IO.Compression.FileSystem
    $zip = [IO.Compression.ZipFile]::OpenRead($ProjectRoot + "/tmp/glfw.zip")
    $zip.Entries | where {($_.FullName -like '*include*') -or ($_.FullName -like '*lib-mingw-w64*')} | 
        foreach{
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