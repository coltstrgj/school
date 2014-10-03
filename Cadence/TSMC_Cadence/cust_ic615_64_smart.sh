CLS_CDSD_COMPATIBILITY_LOCKING=NO; export CLS_CDSD_COMPATIBILITY_LOCKING

CDSHOME=/usr/local/Cadence-new/IC615; export CDSHOME

if [ -d "/usr/local/Cadence-new/MMSIM121" ]
then
	MMSIMHOME=/usr/local/Cadence-new/MMSIM121; export MMSIMHOME
elif [ -d "/usr/local/Cadence-new/MMSIM111" ]
then
	echo "MMSIM121 not installed. Falling back to MMSIM111."
	MMSIMHOME=/usr/local/Cadence-new/MMSIM111; export MMSIMHOME
else
	echo "MMSIM111 not installed. Falling back to MMSIM72. This shouldn't happen."
	MMSIMHOME=/usr/local/Cadence/MMSIM72; export MMSIMHOME
fi


AMSHOME=/usr/local/Cadence/IUS82; export AMSHOME

CDS_VPCM_HOME=$MMSIMHOME/tools/vpcm; export CDS_VPCM_HOME
CDS_AHDLCMI_ENABLE=NO; export CDS_AHDLCMI_ENABLE

CDS_SITE=/usr/local/Cadence-new/IC615/share; export CDS_SITE


ASSURAHOME=/usr/local/Cadence-new/ASSURA41-615; export ASSURAHOME


CDS_Netlisting_Mode=Analog; export CDS_Netlisting_Mode

PATH=$MMSIMHOME/tools/bin:$CDSHOME/tools/bin:$CDSHOME/tools/dfII/bin:$AMSHOME/tools/bin:$AMSHOME/tools/verilog/bin:$AMSHOME/tools/dfII/bin:$CDSHOME/tools/plot/bin:$ASSURAHOME/tools/assura/bin:$CDS_VPCM_HOME/bin:/usr/local/bin:$PATH; export PATH

CDS_AUTO_64BIT=ALL; export CDS_AUTO_64BIT
EDITOR=vi; export EDITOR
CDS_LOAD_ENV=addCWD; export CDS_LOAD_ENV

CDS_LIC_FILE=3430@cadence.engr.colostate.edu; export CDS_LIC_FILE
#CDS_LIC_FILE=/usr/local/Cadence/license.dat; export CDS_LIC_FILE
LM_LICENSE_FILE=$CDS_LIC_FILE; export LM_LICENSE_FILE


LD_LIBRARY_PATH=$AMSHOME/tools/lib:/usr/lib:/usr/dt/lib:/usr/openwin/lib:$CDSHOME/tools.lnx86/lib; export LD_LIBRARY_PATH

if [ -d "/usr/local/Cadence-new/EXT101" ]
then
	QRC_HOME=/usr/local/Cadence-new/EXT101; export QRC_HOME
else
	echo "EXT101 not found. Falling back to EXT81. Only a problem for layout extraction."
	QRC_HOME=/usr/local/Cadence/EXT81; export QRC_HOME
fi

unset QRC_ENABLE_EXTRACTION

PATH=$QRC_HOME/tools/bin:$PATH; export PATH

if [ -d "/usr/local/Cadence-new/MMSIM121" ]
then
	OA_HOME=/usr/local/Cadence-new/MMSIM121/oa_v22.43.006; export OA_HOME
else
	OA_HOME=/usr/local/Cadence-new/IC615/oa_v22.41.029; export OA_HOME
fi
