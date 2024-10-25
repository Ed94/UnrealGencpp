clear-host
$misc = join-path $PSScriptRoot 'helpers/misc.ps1'
. $misc

$path_root       = git rev-parse --show-toplevel
$path_source     = join-path $path_root   'Source'
$path_thirdparty = join-path $path_source 'Thirdparty'
$path_repo       = join-path $path_root   'repo'

verify-path $path_repo

$url_gencpp       = 'https://github.com/Ed94/gencpp.git'

clone-gitrepo $path_repo $url_gencpp

$path_repo_scripts          = join-path $path_repo         'scripts'
$path_repo_unreal           = join-path $path_repo         'unreal'
$path_repo_attribute_tokens = join-path $path_repo_unreal  'enums/AttributeTokens.csv'
$path_attribute_tokens      = join-path $PSScriptRoot      'AttributeTokens.csv'
$path_repo_refactor_unreal  = join-path $path_repo_scripts 'refactor_unreal.ps1'
$path_refactor_unreal       = join-path $PSScriptRoot      'refactor_unreal.ps1'
$path_repo_refactor         = join-path $path_repo_scripts 'helpers/refactor.exe'
$path_refactor              = join-path $PSScriptRoot      'refactor.exe'
Push-Location $path_gencpp_scripts

	Copy-Item -Path $path_attribute_tokens  -Destination $path_repo_attribute_tokens -Force
	Copy-Item -Path $path_refactor_unreal   -Destination $path_repo_refactor_unreal  -Force
	Copy-Item -Path $path_refactor          -Destination $path_refactor

	$build = join-path $path_gencpp_scripts 'build.ci.ps1'
	& $build debug bootstrap unreal

Pop-Location
