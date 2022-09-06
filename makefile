
all:
	make -f MakefileMotorMath.mk 
	make -f MakefilePidControl.mk

clean:
	make -f MakefileMotorMath.mk clean
	make -f MakefilePidControl.mk clean

motormath:
	make -f MakefileMotorMath.mk

pidControl:
	make -f MakefilePidControl.mk 

