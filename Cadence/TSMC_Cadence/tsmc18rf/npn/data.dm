gE#          4                                                       %                     
              (       �                     l       p       t       |       ���������                     �      8      $             P                                           |      $       \       �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           2.2-p001 or above           ( $ 22.04.036       22.04.036       linux_rhel30_gcc411_32 gcc_4.1.1               V��I    V��I                                                                                                                                 	   
                         $                                                                                                                                     ����������������������������������������������������������������                  &             �   E               cdfData ILList cellType bip cellSpacingGrouped cellSpacingNotGrouped               �                                                                                                
            �      �      �      �      �      �      �                               4      �      �      �                                                                                  �       �      �                                                                                                                                                                                                                                                                                                                                                                        ����   �      �   0   �      �          �                                   
                                                                                                    
                                                                                                                         �                                                �       �       �       �       �                                                                            ����   �         �                                                      �       �       �       �       �       �                                                                                      ����   �   	      �         �     �              (promptWidth nil fieldHeight nil fieldWidth nil buttonFieldWidth nil formInitProc nil doneProc nil parameters ((storeDefault "no" defValue "npn5" editable "nil" name "model" type "string" parseAsCEL "yes" parseAsNumber "unset" prompt "Model name" units "" propList nil) (storeDefault "no" callback "tsmc18rf_npnCB()" choices ("10x10" "5x5" "2x2") defValue "5x5" name "EmitterSize" type "cyclic" parseAsCEL "unset" parseAsNumber "unset" prompt "Emitter Size" units "" propList nil) (storeDefault "no" defValue "2.5e-11" editable "nil" name "area" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Area" units "" propList nil) (storeDefault "no" defValue "1" display "nil" editable "nil" name "area_f" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Area Factor" units "" propList nil) (storeDefault "no" callback "tsmc18rf_npnCB()" defValue "1" editable "deGetEditCellView()->cellViewType != \"maskLayout\"" name "m" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Multiplier" units "" propList nil) (storeDefault "no" defValue nil display "and( nil deGetEditCellView()->cellViewType != \"maskLayout\" )" name "off" type "boolean" parseAsCEL "unset" parseAsNumber "unset" prompt "Device initially off" units "" propList nil) (storeDefault "no" choices ("off" "fwd" "rev" "sat") defValue "fwd" display "deGetEditCellView()->cellViewType != \"maskLayout\"" name "region" type "cyclic" parseAsCEL "unset" parseAsNumber "unset" prompt "Estimated operating region" units "" propList nil) (storeDefault "no" choices ("No" "Yes") defValue "No" display "nil" name "mode" type "cyclic" parseAsCEL "unset" parseAsNumber "unset" prompt "Linearized Region" units "" propList nil) (storeDefault "no" defValue "5e-06" display "nil" name "w" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Emitter Width" units "" propList nil) (storeDefault "no" defValue "5e-06" display "nil" name "l" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Emitter Length" units "" propList nil) (storeDefault "no" defValue "npn5" display "nil" editable "nil" name "lxUseCell" type "string" parseAsCEL "yes" parseAsNumber "unset" prompt "Layout Cell Used" units "" propList nil) (storeDefault "no" defValue "2e-05" display "nil" editable "nil" name "wCdl" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Perimeter of emitter area" units "" propList nil) (storeDefault "no" defValue "1.25e-06" display "nil" editable "nil" name "lCdl" type "string" parseAsCEL "yes" parseAsNumber "yes" prompt "Area/Perimeter of emitter area" units "" propList nil)) propList (modelLabelSet "bf is vaf" opPointLabelSet "betadc ic vce" paramLabelSet "-model m area" simInfo (nil ams (nil otherParameters \(model\) instParameters (model trise region m) termOrder (C B E) isPrimitive t) ads (nil componentName nil instParameters (_M Region) netlistProcedure ADSsimCompPrim otherParameters (model) propMapping (nil _M m Region region) termMapping (nil C ":P1" B ":P2" E ":P3") termOrder (C B E) typeMapping (nil Region region) uselib nil) UltraSim (nil namePrefix "Q" propMapping (nil) termMapping (nil C \:c B \:b E \:e) termOrder (C B E) instParameters (m) otherParameters (model)) spectre (nil termMapping (nil C \:c B \:b E \:e) termOrder (C B E) instParameters (m region) otherParameters (model)) hspiceS (nil netlistProcedure ansSpiceDevPrim instParameters (area m) otherParameters (model) componentName hnpn termOrder (C B E) propMapping (nil vce Vce ic Ic area area_f) namePrefix Q current port) auLvs (nil netlistProcedure ansLvsCompPrim instParameters (m area) componentName npn termOrder (C B E) namePrefix Q) auCdl (nil netlistProcedure ansCdlCompPrim propMapping (nil M m EA area W wCdl L lCdl) instParameters (EA M W L) namePrefix "Q" componentName npn termOrder (C B E) modelName NV))))   d      �                                                �       �       �       �       �                                                                                ����   �                       gE#