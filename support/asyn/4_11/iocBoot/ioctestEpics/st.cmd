dbLoadDatabase("../../dbd/testEpics.dbd")
testEpics_registerRecordDeviceDriver(pdbbase)

int32DriverInit("int32",-32768,32767)
dbLoadRecords("../../db/devInt32.db")

uint32DigitalDriverInit("digital")
dbLoadRecords("../../db/devDigital.db")

echoDriverInit("echo",0.1,0,0)
dbLoadRecords("../../db/devOctet.db","PORT=echo,ADDR=0")

dbLoadRecords("../../db/asynRecord.db","P=asyn,R=Record,PORT=digital,ADDR=0,OMAX=0,IMAX=0")

iocInit()
