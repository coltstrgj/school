;;; If you rename the library you will have to change the
;;; libName definition in the following let statement.
let( ( (libName "tsmc18rf") libId libPath file element)
;;
;; Load PDK Skill Code
;;
  libId = ddGetObj( libName )
  if( ddIsId( libId ) then
    libPath = ddGetObjReadPath( libId )
    envSetVal("layoutXL" "setPPConn" 'boolean nil)
;    envSetVal( "layout" "xSnapSpacing" 'float 0.005 )
;    envSetVal( "layout" "ySnapSpacing" 'float 0.005 )
    libPath = strcat( libPath "/../skill")
    foreach( file setof(element getDirFiles(libPath) equal(".cbe" index(element ".cbe")))
      printf( "Initializing %s from libInit.il for library %s...\n" file libName )
      load( strcat( libPath sprintf(nil "/%s" file)))
    )
    foreach( file setof(element getDirFiles(libPath) equal(".ile" index(element ".ile")))
      printf( "Initializing %s from libInit.il for library %s...\n" file libName )
      load( strcat( libPath sprintf(nil "/%s" file)))
    )
    foreach( file setof(element getDirFiles(libPath) equal(".cb" index(element ".cb")))
      printf( "Initializing %s from libInit.il for library %s...\n" file libName )
      load( strcat( libPath sprintf(nil "/%s" file)))
    )
    foreach( file setof(element getDirFiles(libPath) equal(".il" index(element ".il")))
      printf( "Initializing %s from libInit.il for library %s...\n" file libName )
      load( strcat( libPath sprintf(nil "/%s" file)))
    )
  else
    printf( "An error occured while initializing the libInit.il file.\n" )
    printf( "The library, %s, specified in this file, could\n" libName )
    printf( "not be found. If you have:\n" )
    printf( "    o   moved/copied the library to a new name.\n" )
    printf( "    o   edited this file and made a typographical error.\n" )
    printf( "    o   copied this file from another library.\n" )
    printf( "you must edit the libInit.il file and correct the\n" )
    printf( "library name.\n" )
  )
;;
;; Set the Spectre Model Path
;;
  if(isContextLoaded("schView") then
     envSetVal("asimenv.startup" "simulator" 'string "spectre")
     libPath = ddGetObjReadPath( libId )
     asiSetEnvOptionVal(asiGetTool('spectre) "modelFiles"
        list(
           list(strcat(getWorkingDir() "/tsmc18rf/rf018.scs") "tt")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_3v")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_na")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_3vna")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_m")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_3m")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_bip")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_bip3")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "dio")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "dio3")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "dio_dnw")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_res")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_mim")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfmos")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfmos33")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfmim")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfind")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfmvar")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfjvar")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfres_sa")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfres_rpo")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfres_hri")
; 	    list(strcat( libPath "/../models/spectre/rf018.scs") "tt_rfesd")
;           list(strcat( libPath "/../models/spectre/rf018.scs") "tt_bbmvar")

        )
     )

     asiSetEnvOptionVal(asiGetTool('hspiceS) "modelPath" strcat(libPath "/../models/hspice") )
     asiSetEnvOptionVal(asiGetTool('hspiceS) "includeFile" "hspice.mdl")
  if(getd('ADSsim) then
     asiSetEnvOptionVal(asiGetTool('ADSsim) "modelFiles"
        list(
           ;list(strcat( libPath "/../models/ADS/rf018_inc.net") "")
           ;list(strcat( libPath "/../models/ADS/ResModel.net") "res_t")
	)
     )
    );end ADS if
  ); if schematic context is loaded
;;
;; Set the VXL significan Digits
;;
  when( getd('aelPushSignifDigits)
     aelPushSignifDigits(6)
  )

  auCdlCDFPinCntrl = 't

)
