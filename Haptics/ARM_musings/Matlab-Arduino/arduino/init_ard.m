ard = serial('COM7', 'BAUD', 9600)
ard.BytesAvailableFcn = @Servo_test;
fopen(ard);