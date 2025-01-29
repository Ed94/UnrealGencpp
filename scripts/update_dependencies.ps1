clear-host
$misc = join-path $PSScriptRoot 'helpers/misc.ps1'
. $misc

$path_root         = git rev-parse --show-toplevel
$path_build        = join-path $path_root         'build'
$path_source       = join-path $path_root         'Source'
$path_thirdparty   = join-path $path_source       'Thirdparty'
$path_UnrealGencpp = join-path $path_source       'UnrealGencpp'
$path_gencpp       = join-path $path_UnrealGencpp 'gencpp'

verify-path $path_build

$path_repo  = join-path $path_root   'repo'
$url_gencpp = 'https://github.com/Ed94/gencpp.git'

update-gitrepo $path_repo $url_gencpp

$path_repo_scripts          = join-path $path_repo         'scripts'
$path_repo_unreal           = join-path $path_repo         'gen_unreal_engine'
$path_repo_unreal_gen       = join-path $path_repo_unreal  'gen'
$path_repo_attribute_tokens = join-path $path_repo_unreal  'enums/AttributeTokens.csv'
$path_attribute_tokens      = join-path $PSScriptRoot      'AttributeTokens.csv'
$path_repo_refactor_unreal  = join-path $path_repo_scripts 'unreal.refactor'
$path_refactor_unreal       = join-path $PSScriptRoot      'unreal.refactor'
Push-Location $path_gencpp_scripts

	Copy-Item -Path $path_attribute_tokens  -Destination $path_repo_attribute_tokens -Force
	Copy-Item -Path $path_refactor_unreal   -Destination $path_repo_refactor_unreal  -Force

	$build = join-path $path_repo_scripts 'build.ci.ps1'
	& $build debug bootstrap unreal

	Copy-Item -Path $path_repo_unreal_gen\* -Destination $path_gencpp -Force

Pop-Location
