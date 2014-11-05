<?xml version='1.0'?>
<Project Type="Project" LVVersion="8208000">
   <Item Name="My Computer" Type="My Computer">
      <Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="server.tcp.port" Type="Int">0</Property>
      <Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="specify.custom.address" Type="Bool">false</Property>
      <Item Name="ECE33x.lvlib" Type="Library" URL="ECE33x.lvlib">
         <Item Name="ECE33x_Library.lvlib" Type="Library" URL="ECE33x_Library/ECE33x/ECE33x_Library.lvlib">
            <Item Name="Examples" Type="Folder">
               <Item Name="Save Data to CSV File Example 1.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Save Data to CSV File Example 1.vi"/>
               <Item Name="Power Supply Stepping Example.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Examples/Power Supply Stepping Example.vi"/>
               <Item Name="Power Supply Stepping Example 2.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Examples/Power Supply Stepping Example 2.vi"/>
               <Item Name="Power Supply Stepping Example 3.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Power Supply Stepping Example 3.vi"/>
               <Item Name="Power Supply Sweep and Plot.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Power Supply Sweep and Plot.vi"/>
               <Item Name="Power Supply Sweep and Plot with Meter.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Power Supply Sweep and Plot with Meter.vi"/>
               <Item Name="Frequency Response Example 1.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Frequency Response Example 1.vi"/>
               <Item Name="FFT and FRF Example 1.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/FFT and FRF Example 1.vi"/>
               <Item Name="MOSFET Vgs Eq Vds Sweep.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/MOSFET Vgs Eq Vds Sweep.vi"/>
               <Item Name="Power MOSFET Vgs Sweep.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Power MOSFET Vgs Sweep.vi"/>
               <Item Name="Power MOSFET Vds Sweep.vi" Type="VI" URL="ECE33x_Library/ECE33x/Examples/Power MOSFET Vds Sweep.vi"/>
            </Item>
            <Item Name="Private" Type="Folder"/>
            <Item Name="Public" Type="Folder">
               <Item Name="Utility" Type="Folder">
                  <Item Name="Low Level" Type="Folder">
                     <Item Name="CommentDialog.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/CommentDialog.vi"/>
                     <Item Name="FilenamePrompt.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/FilenamePrompt.vi"/>
                     <Item Name="Pad Array with Mirrored Data.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/Pad Array with Mirrored Data.vi"/>
                     <Item Name="PrependDateTimeToString.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/PrependDateTimeToString.vi"/>
                     <Item Name="Append to Filename.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/Append to Filename.vi"/>
                     <Item Name="Waveform to XY Data.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Low Level/Waveform to XY Data.vi"/>
                  </Item>
                  <Item Name="Save Data to CSV File.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Save Data to CSV File.vi"/>
                  <Item Name="Generic Zero Phase Hash Filter.vi" Type="VI" URL="ECE33x_Library/ECE33x/Public/Utility/Generic Zero Phase Hash Filter.vi"/>
               </Item>
            </Item>
            <Item Name="ECE33x VI Tree.vi" Type="VI" URL="ECE33x_Library/ECE33x/ECE33x VI Tree.vi"/>
            <Item Name="dir.mnu" Type="Document" URL="ECE33x_Library/ECE33x/dir.mnu"/>
         </Item>
         <Item Name="HP34401A.lvlib" Type="Library" URL="ECE33x_Library/HP34401A/HP34401A.lvlib">
            <Item Name="ECE33x" Type="Folder">
               <Item Name="Examples" Type="Folder"/>
               <Item Name="Private" Type="Folder"/>
               <Item Name="Public" Type="Folder"/>
            </Item>
            <Item Name="Agilent 34401" Type="Folder">
               <Item Name="Examples" Type="Folder">
                  <Item Name="Agilent 34401 Acquire and Chart - External Triggered.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Acquire and Chart - External Triggered.vi"/>
                  <Item Name="Agilent 34401 Acquire and Chart - Pretriggered.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Acquire and Chart - Pretriggered.vi"/>
                  <Item Name="Agilent 34401 Acquire and Chart - Triggered.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Acquire and Chart - Triggered.vi"/>
                  <Item Name="Agilent 34401 Acquire and Graph - SW Triggered.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Acquire and Graph - SW Triggered.vi"/>
                  <Item Name="Agilent 34401 Read Multiple Measurements.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Read Multiple Measurements.vi"/>
                  <Item Name="Agilent 34401 Read Single Measurement.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Read Single Measurement.vi"/>
                  <Item Name="Agilent 34401 Read Temperature Measurement (RTD).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Read Temperature Measurement (RTD).vi"/>
                  <Item Name="Agilent 34401 Read Transient Measurement.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Read Transient Measurement.vi"/>
                  <Item Name="Agilent 34401.bin3" Type="Document" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401.bin3"/>
               </Item>
               <Item Name="Public" Type="Folder">
                  <Item Name="Configure" Type="Folder">
                     <Item Name="Low Level" Type="Folder">
                        <Item Name="Configure Multipoint.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Low Level/Configure Multipoint.vi"/>
                        <Item Name="Configure Trigger.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Low Level/Configure Trigger.vi"/>
                     </Item>
                     <Item Name="Configure AC Filter.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure AC Filter.vi"/>
                     <Item Name="Configure Aperture.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Aperture.vi"/>
                     <Item Name="Configure Autozero.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Autozero.vi"/>
                     <Item Name="Configure DC Input Resistance.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure DC Input Resistance.vi"/>
                     <Item Name="Configure Integration.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Integration.vi"/>
                     <Item Name="Configure Math.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Math.vi"/>
                     <Item Name="Configure Measurement.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Measurement.vi"/>
                     <Item Name="Configure Offset Compensation.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Offset Compensation.vi"/>
                     <Item Name="Configure Temperature (RTD).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Temperature (RTD).vi"/>
                     <Item Name="Configure Temperature (Thermistor).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Temperature (Thermistor).vi"/>
                     <Item Name="Configure Temperature.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Configure/Configure Temperature.vi"/>
                  </Item>
                  <Item Name="Data" Type="Folder">
                     <Item Name="Low Level" Type="Folder">
                        <Item Name="Fetch Measurement.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Low Level/Fetch Measurement.vi"/>
                        <Item Name="Initiate Measurement.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Low Level/Initiate Measurement.vi"/>
                        <Item Name="Query Questionable Data Register.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Low Level/Query Questionable Data Register.vi"/>
                        <Item Name="Send Software Trigger.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Low Level/Send Software Trigger.vi"/>
                     </Item>
                     <Item Name="Read (Math).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Read (Math).vi"/>
                     <Item Name="Read (Multiple Points).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Read (Multiple Points).vi"/>
                     <Item Name="Read (Single Point).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Read (Single Point).vi"/>
                     <Item Name="Read (Transient).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Read (Transient).vi"/>
                     <Item Name="Read.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Data/Read.vi"/>
                  </Item>
                  <Item Name="Obsolete" Type="Folder">
                     <Item Name="Fetch (Internal Buffer).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Fetch (Internal Buffer).vi"/>
                     <Item Name="Fetch (Output Buffer).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Fetch (Output Buffer).vi"/>
                     <Item Name="Fetch.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Fetch.vi"/>
                     <Item Name="Initiate (Internal Buffer).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Initiate (Internal Buffer).vi"/>
                     <Item Name="Initiate (Output Buffer).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Initiate (Output Buffer).vi"/>
                     <Item Name="Initiate.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Obsolete/Initiate.vi"/>
                  </Item>
                  <Item Name="Utility" Type="Folder">
                     <Item Name="Device Clear.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Device Clear.vi"/>
                     <Item Name="Error Query.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Error Query.vi"/>
                     <Item Name="Reset.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Reset.vi"/>
                     <Item Name="Revision Query.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Revision Query.vi"/>
                     <Item Name="Save-Recall Instrument Settings.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Save-Recall Instrument Settings.vi"/>
                     <Item Name="Self-Test.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/Self-Test.vi"/>
                     <Item Name="System Options.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Utility/System Options.vi"/>
                  </Item>
                  <Item Name="AG34401 VI Tree.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/AG34401 VI Tree.vi"/>
                  <Item Name="Close.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Close.vi"/>
                  <Item Name="Initialize.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Public/Initialize.vi"/>
               </Item>
               <Item Name="Private" Type="Folder">
                  <Item Name="Control Mode.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Control Mode.vi"/>
                  <Item Name="Default Instrument Setup.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Default Instrument Setup.vi"/>
                  <Item Name="Extended User Data.ctl" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Extended User Data.ctl"/>
                  <Item Name="Extended User Data.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Extended User Data.vi"/>
                  <Item Name="Fetch Measurement (Fast Read).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Fetch Measurement (Fast Read).vi"/>
                  <Item Name="Fetch Measurement (Fetch).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Fetch Measurement (Fetch).vi"/>
                  <Item Name="Fetch Measurement (Read).vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Fetch Measurement (Read).vi"/>
                  <Item Name="Read STB.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Private/Read STB.vi"/>
               </Item>
               <Item Name="Agilent 34401 Readme.html" Type="Document" URL="ECE33x_Library/HP34401A/Agilent 34401/Agilent 34401 Readme.html"/>
               <Item Name="dir.mnu" Type="Document" URL="ECE33x_Library/HP34401A/Agilent 34401/dir.mnu"/>
            </Item>
            <Item Name="Agilent 34401 Read Single Measurement No Reset.vi" Type="VI" URL="ECE33x_Library/HP34401A/Agilent 34401/Examples/Agilent 34401 Read Single Measurement No Reset.vi"/>
         </Item>
         <Item Name="HP33120A.lvlib" Type="Library" URL="ECE33x_Library/HP33120A/HP33120A.lvlib">
            <Item Name="ECE33x" Type="Folder">
               <Item Name="Examples" Type="Folder">
                  <Item Name="Setup Standard Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/ECE33x/Examples/Setup Standard Waveform.vi"/>
               </Item>
               <Item Name="Private" Type="Folder"/>
               <Item Name="Public" Type="Folder">
                  <Item Name="Triggered_Ramp.vi" Type="VI" URL="ECE33x_Library/HP33120A/ECE33x/Public/Triggered_Ramp.vi"/>
                  <Item Name="Triggered_Rectangular_Pulse.vi" Type="VI" URL="ECE33x_Library/HP33120A/ECE33x/Public/Triggered_Rectangular_Pulse.vi"/>
               </Item>
            </Item>
            <Item Name="Agilent 33XXX Series" Type="Folder">
               <Item Name="Examples" Type="Folder">
                  <Item Name="Agilent 33XXX Series Generate Arbitrary Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series Generate Arbitrary Waveform.vi"/>
                  <Item Name="Agilent 33XXX Series Generate Frequency Sweep - SW Triggered.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series Generate Frequency Sweep - SW Triggered.vi"/>
                  <Item Name="Agilent 33XXX Series Generate Frequency Sweep.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series Generate Frequency Sweep.vi"/>
                  <Item Name="Agilent 33XXX Series Generate Modulated Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series Generate Modulated Waveform.vi"/>
                  <Item Name="Agilent 33XXX Series Generate Standard Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series Generate Standard Waveform.vi"/>
                  <Item Name="Agilent 33XXX Series.bin3" Type="Document" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Examples/Agilent 33XXX Series.bin3"/>
               </Item>
               <Item Name="Private" Type="Folder">
                  <Item Name="Default Instrument Setup.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Private/Default Instrument Setup.vi"/>
                  <Item Name="Scale Arbitrary Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Private/Scale Arbitrary Waveform.vi"/>
               </Item>
               <Item Name="Public" Type="Folder">
                  <Item Name="Action-Status" Type="Folder">
                     <Item Name="Low Level" Type="Folder">
                        <Item Name="Send Software Trigger.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Action-Status/Low Level/Send Software Trigger.vi"/>
                     </Item>
                     <Item Name="Clear Arbitrary Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Action-Status/Clear Arbitrary Waveform.vi"/>
                     <Item Name="Enable Output.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Action-Status/Enable Output.vi"/>
                  </Item>
                  <Item Name="Configure" Type="Folder">
                     <Item Name="Low Level" Type="Folder">
                        <Item Name="Configure Trigger.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Low Level/Configure Trigger.vi"/>
                     </Item>
                     <Item Name="Configure Arbitrary Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Arbitrary Waveform.vi"/>
                     <Item Name="Configure Duty Cycle.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Duty Cycle.vi"/>
                     <Item Name="Configure Frequency Sweep.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Frequency Sweep.vi"/>
                     <Item Name="Configure Modulation (Amplitude).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Amplitude).vi"/>
                     <Item Name="Configure Modulation (Burst).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Burst).vi"/>
                     <Item Name="Configure Modulation (Frequency).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Frequency).vi"/>
                     <Item Name="Configure Modulation (Frequency-Shift Keying).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Frequency-Shift Keying).vi"/>
                     <Item Name="Configure Modulation (Phase).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Phase).vi"/>
                     <Item Name="Configure Modulation (Pulse Width).vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation (Pulse Width).vi"/>
                     <Item Name="Configure Modulation.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Modulation.vi"/>
                     <Item Name="Configure Output Impedance.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Output Impedance.vi"/>
                     <Item Name="Configure Pulse.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Pulse.vi"/>
                     <Item Name="Configure Ramp Symmetry.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Ramp Symmetry.vi"/>
                     <Item Name="Configure Standard Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Configure Standard Waveform.vi"/>
                     <Item Name="Create Arbitrary Waveform.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Configure/Create Arbitrary Waveform.vi"/>
                  </Item>
                  <Item Name="Utility" Type="Folder">
                     <Item Name="Error Query.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Utility/Error Query.vi"/>
                     <Item Name="Reset.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Utility/Reset.vi"/>
                     <Item Name="Revision Query.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Utility/Revision Query.vi"/>
                     <Item Name="Self-Test.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Utility/Self-Test.vi"/>
                  </Item>
                  <Item Name="AG33XXX VI Tree.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/AG33XXX VI Tree.vi"/>
                  <Item Name="Close.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Close.vi"/>
                  <Item Name="Initialize.vi" Type="VI" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/Public/Initialize.vi"/>
               </Item>
               <Item Name="dir.mnu" Type="Document" URL="ECE33x_Library/HP33120A/Agilent 33XXX Series/dir.mnu"/>
            </Item>
         </Item>
         <Item Name="HP54600B.lvlib" Type="Library" URL="ECE33x_Library/HP54600B/HP54600B.lvlib">
            <Item Name="HP54600B Oscilloscope" Type="Folder">
               <Item Name="Public" Type="Folder">
                  <Item Name="HP546XXX" Type="Folder">
                     <Item Name="HP54600A Channel Config.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A Channel Config.vi"/>
                     <Item Name="HP54600A Miscellaneous.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A Miscellaneous.vi"/>
                     <Item Name="HP54600A Trace Functions.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A Trace Functions.vi"/>
                     <Item Name="HP54600A-610B Cursor.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A-610B Cursor.vi"/>
                     <Item Name="HP54600A-610B Digitize.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A-610B Digitize.vi"/>
                     <Item Name="HP54600A-610B Edge Trigger.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A-610B Edge Trigger.vi"/>
                     <Item Name="HP54600A-610B Measurements.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A-610B Measurements.vi"/>
                     <Item Name="HP54600A-610B Read Waveform.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54600A-610B Read Waveform.vi"/>
                     <Item Name="HP54601A-602B Channel Config.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Channel Config.vi"/>
                     <Item Name="HP54601A-602B Cursor.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Cursor.vi"/>
                     <Item Name="HP54601A-602B Digitize.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Digitize.vi"/>
                     <Item Name="HP54601A-602B Edge Trigger.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Edge Trigger.vi"/>
                     <Item Name="HP54601A-602B Measurements.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Measurements.vi"/>
                     <Item Name="HP54601A-602B Miscellaneous.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Miscellaneous.vi"/>
                     <Item Name="HP54601A-602B Read Waveform.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Read Waveform.vi"/>
                     <Item Name="HP54601A-602B Trace Functions.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54601A-602B Trace Functions.vi"/>
                     <Item Name="HP54602B Save-Recall.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54602B Save-Recall.vi"/>
                     <Item Name="HP54610B Channel Config.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54610B Channel Config.vi"/>
                     <Item Name="HP54610B Miscellaneous.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54610B Miscellaneous.vi"/>
                     <Item Name="HP54610B Trace Functions.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54610B Trace Functions.vi"/>
                     <Item Name="HP54655A Adjust Step.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54655A Adjust Step.vi"/>
                     <Item Name="HP54655A Mask Template Test.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54655A Mask Template Test.vi"/>
                     <Item Name="HP54655A Protect Sequence.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54655A Protect Sequence.vi"/>
                     <Item Name="HP54655A Upload-Download Seq Setup.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54655A Upload-Download Seq Setup.vi"/>
                     <Item Name="HP54657A Create Mask.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Create Mask.vi"/>
                     <Item Name="HP54657A Define Cursors.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Define Cursors.vi"/>
                     <Item Name="HP54657A Delay &amp; Threshold.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Delay &amp; Threshold.vi"/>
                     <Item Name="HP54657A Display Trace.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Display Trace.vi"/>
                     <Item Name="HP54657A Function I.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Function I.vi"/>
                     <Item Name="HP54657A Function II (FFT).vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Function II (FFT).vi"/>
                     <Item Name="HP54657A Function II.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Function II.vi"/>
                     <Item Name="HP54657A Mask Test On-Off.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Mask Test On-Off.vi"/>
                     <Item Name="HP54657A Measurements.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Measurements.vi"/>
                     <Item Name="HP54657A Save-Recall Trace.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Save-Recall Trace.vi"/>
                     <Item Name="HP54657A Statistics.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Statistics.vi"/>
                     <Item Name="HP54657A Test Options.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP54657A Test Options.vi"/>
                     <Item Name="HP546XXA Display Options.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXA Display Options.vi"/>
                     <Item Name="HP546XXA Timebase Config.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXA Timebase Config.vi"/>
                     <Item Name="HP546XXA-610B Save-Recall.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXA-610B Save-Recall.vi"/>
                     <Item Name="HP546XXB Display Options.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXB Display Options.vi"/>
                     <Item Name="HP546XXB Timebase Config.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXB Timebase Config.vi"/>
                     <Item Name="HP546XXX Application.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Application.vi"/>
                     <Item Name="HP546XXX Autoscale.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Autoscale.vi"/>
                     <Item Name="HP546XXX Close.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Close.vi"/>
                     <Item Name="HP546XXX Config Acquisition.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Config Acquisition.vi"/>
                     <Item Name="HP546XXX Error Message.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Error Message.vi"/>
                     <Item Name="HP546XXX Error Query.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Error Query.vi"/>
                     <Item Name="HP546XXX Getting Started.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Getting Started.vi"/>
                     <Item Name="HP546XXX Initialize.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Initialize.vi"/>
                     <Item Name="HP546XXX Math Option.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Math Option.vi"/>
                     <Item Name="HP546XXX Reset.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Reset.vi"/>
                     <Item Name="HP546XXX Self-Test.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Self-Test.vi"/>
                     <Item Name="HP546XXX Storage.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Storage.vi"/>
                     <Item Name="HP546XXX Time-Volt Query.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Time-Volt Query.vi"/>
                     <Item Name="HP546XXX TV Trigger Mode.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX TV Trigger Mode.vi"/>
                     <Item Name="HP546XXX Update Error Cluster.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX/HP546XXX Update Error Cluster.vi"/>
                  </Item>
                  <Item Name="ACTSTAT.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/ACTSTAT.MNU"/>
                  <Item Name="APPLIC.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/APPLIC.MNU"/>
                  <Item Name="CONFIG.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/CONFIG.MNU"/>
                  <Item Name="DATA.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/DATA.MNU"/>
                  <Item Name="UTIL.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/UTIL.MNU"/>
                  <Item Name="DIR.MNU" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/DIR.MNU"/>
                  <Item Name="hp546xxx Readme.html" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/hp546xxx Readme.html"/>
                  <Item Name="HP546XXX.llx" Type="Document" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX.llx"/>
                  <Item Name="HP546XXX VI Tree.vi" Type="VI" URL="ECE33x_Library/HP54600B/HP54600B Oscilloscope/Public/HP546XXX VI Tree.vi"/>
               </Item>
            </Item>
            <Item Name="ECE33x" Type="Folder">
               <Item Name="Examples" Type="Folder">
                  <Item Name="HP54600B Read And Save Data.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Examples/HP54600B Read And Save Data.vi"/>
                  <Item Name="HP54600B Autoscale.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Examples/HP54600B Autoscale.vi"/>
               </Item>
               <Item Name="Private" Type="Folder">
                  <Item Name="PrependDateTimeToString.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/PrependDateTimeToString.vi"/>
               </Item>
               <Item Name="Public" Type="Folder">
                  <Item Name="Utility" Type="Folder">
                     <Item Name="Low Level" Type="Folder">
                        <Item Name="CommentDialog.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/Utility/Low Level/CommentDialog.vi"/>
                        <Item Name="FilenamePrompt.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/Utility/Low Level/FilenamePrompt.vi"/>
                     </Item>
                     <Item Name="Save Data to CSV File.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/Utility/Save Data to CSV File.vi"/>
                  </Item>
                  <Item Name="HP54600B_IsChanOn.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/HP54600B_IsChanOn.vi"/>
                  <Item Name="HP54600B_ReadBothChannels.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/HP54600B_ReadBothChannels.vi"/>
                  <Item Name="HP54600B_ReadChannelTrace.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/HP54600B_ReadChannelTrace.vi"/>
                  <Item Name="HP54600B_readconfig.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/HP54600B_readconfig.vi"/>
                  <Item Name="HP54600B_SaveTracesAndScopeConfig.vi" Type="VI" URL="ECE33x_Library/HP54600B/ECE33x/Public/HP54600B_SaveTracesAndScopeConfig.vi"/>
               </Item>
            </Item>
         </Item>
         <Item Name="HPE3631A.lvlib" Type="Library" URL="ECE33x_Library/HPE3631A/HPE3631A.lvlib">
            <Item Name="Agilent E363X Series" Type="Folder">
               <Item Name="Examples" Type="Folder">
                  <Item Name="Agilent E363X Series Output DC Volts - OVP OCP.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Examples/Agilent E363X Series Output DC Volts - OVP OCP.vi"/>
                  <Item Name="Agilent E363X Series Output DC Volts - Triggered.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Examples/Agilent E363X Series Output DC Volts - Triggered.vi"/>
                  <Item Name="Agilent E363X Series Output DC Volts.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Examples/Agilent E363X Series Output DC Volts.vi"/>
                  <Item Name="Agilent E363X Series.bin3" Type="Document" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Examples/Agilent E363X Series.bin3"/>
               </Item>
               <Item Name="Private" Type="Folder">
                  <Item Name="Default Instrument Setup.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Private/Default Instrument Setup.vi"/>
               </Item>
               <Item Name="Public" Type="Folder">
                  <Item Name="Action-Status" Type="Folder">
                     <Item Name="Low-Level" Type="Folder">
                        <Item Name="Initiate.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Action-Status/Low-Level/Initiate.vi"/>
                        <Item Name="Send Software Trigger.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Action-Status/Low-Level/Send Software Trigger.vi"/>
                     </Item>
                     <Item Name="Output Protection Status.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Action-Status/Output Protection Status.vi"/>
                     <Item Name="Reset Output Protection.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Action-Status/Reset Output Protection.vi"/>
                  </Item>
                  <Item Name="Configure" Type="Folder">
                     <Item Name="Low-Level" Type="Folder">
                        <Item Name="Configure Trigger.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Low-Level/Configure Trigger.vi"/>
                     </Item>
                     <Item Name="Configure Coupling.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure Coupling.vi"/>
                     <Item Name="Configure Current Limit.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure Current Limit.vi"/>
                     <Item Name="Configure Output Range.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure Output Range.vi"/>
                     <Item Name="Configure Output.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure Output.vi"/>
                     <Item Name="Configure OVP.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure OVP.vi"/>
                     <Item Name="Configure Tracking.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Configure/Configure Tracking.vi"/>
                  </Item>
                  <Item Name="Data" Type="Folder">
                     <Item Name="Read Output.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Data/Read Output.vi"/>
                  </Item>
                  <Item Name="Utility" Type="Folder">
                     <Item Name="Error Query.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Utility/Error Query.vi"/>
                     <Item Name="Reset.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Utility/Reset.vi"/>
                     <Item Name="Revision Query.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Utility/Revision Query.vi"/>
                     <Item Name="Save-Recall Setup.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Utility/Save-Recall Setup.vi"/>
                     <Item Name="Self-Test.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Utility/Self-Test.vi"/>
                  </Item>
                  <Item Name="AG363x VI Tree.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/AG363x VI Tree.vi"/>
                  <Item Name="Close.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Close.vi"/>
                  <Item Name="Initialize.vi" Type="VI" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Public/Initialize.vi"/>
               </Item>
               <Item Name="Agilent E363X Series Readme.html" Type="Document" URL="ECE33x_Library/HPE3631A/Agilent E363X Series/Agilent E363X Series Readme.html"/>
            </Item>
            <Item Name="ECE33x" Type="Folder">
               <Item Name="Examples" Type="Folder"/>
               <Item Name="Private" Type="Folder"/>
               <Item Name="Public" Type="Folder">
                  <Item Name="Read_Output_Values.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Public/Read_Output_Values.vi"/>
                  <Item Name="Setup_Outputs.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Public/Setup_Outputs.vi"/>
               </Item>
            </Item>
            <Item Name="dir.mnu" Type="Document" URL="ECE33x_Library/HPE3631A/dir.mnu"/>
            <Item Name="Setup_Output.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Public/Setup_Output.vi"/>
            <Item Name="Read_Output_Value.vi" Type="VI" URL="ECE33x_Library/HPE3631A/ECE33x/Public/Read_Output_Value.vi"/>
         </Item>
      </Item>
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
</Project>
