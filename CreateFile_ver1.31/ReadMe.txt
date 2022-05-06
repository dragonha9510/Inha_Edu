Befor Use This
	 : 해당 폴더를 통째로 사용할 프로젝트 폴더에 붙여 넣어야 합니다.

ver 1.0 _
	# 해당 프로그램 사용시 폴더명과 경로를 다음과 같이 유지하여야 합니다.
		1) (프로젝트 폴더)/Engine/Resources/~ 
		2) (프로젝트 폴더)/Engine/Systems/~
		3) (프로젝트 폴더)/Engine/Utilities/~
		4) (프로젝트 폴더)/Engine/Headers/~
		5) (프로젝트 폴더)/Engine/Exports/~
		6) (프로젝트 폴더)/Client/~

	# 중복된 이름으로 파일을 생성하게 된다면 자동으로 덮어 씌어집니다. 사용에 유의 바랍니다.

ver 1.1 _
	# Client -> Class 생성 시 Header파일에 #include "stdafx.h" 를 표기하도록 추가하였습니다.
	# Engine -> Inline 기능이 추가되었습니다. 
	  ->(해당 경로에 파일을 만들어 줄 뿐 기본 표기 이외의 표기는 하지 않습니다.)

ver 1.2 _ 
	# Engine -> Class 생성 시 ENGINE_DLL 을 표기하도록 추가하였습니다. ( 주석 (a) 참고 )

ver 1.3 _
	# 파일 생성 후에 대상 폴더를 여는 기능을 추가하였습니다. 생성된 파일의 ".h" 가 선택된 채로
	 폴더가 실행됩니다.

ver 1.31 _
	# 대상 폴더 열기 선택 시 폴더의 경로가 잘못 입력되는 버그를 수정 하였습니다.



// 주석
	(a) . 	#ifdef ENGINE_EXPORTS
		#define ENGINE_DLL _declspec(dllexport)
		#else
		#define ENGINE_DLL _declspec(dllimport)
		#endif
