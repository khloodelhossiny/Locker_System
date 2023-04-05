# Locker_System
Design a hotel room Locker system that enable the guest to set a password, this password should never delete even if the microcontroller power is off

### Video 
https://drive.google.com/file/d/1_-csCN-yBDZ9gS5pvXOodh8jj-5E2OOz/view?usp=share_link

### The System consists of :
1. ATMEGA32
2. Keypad
3. LCD
4. EEPROM
5. Buzzer

### Details:
1. Pressing on any button will make the buzzer on for 100msec.
2. First time password saved is 0000.
3. User should enter 0000 to open locker at first time.
4. To change password user should press on ‘/’ buzzer will be on for 3 second then off user should enter 4 digit password then press on ‘/’ again to save password
5. To close the locker, you should press only on ‘*’
6. To open the locker, enter 4 digit password (lcd display * each time you enter a digit for password, then display locker opened if right password and Try again if wrong password and a buzzer will be on for 3 second then off re-enter password again.
7. To reset password: (locker must be in opened state): insert 10 zeros the password will back to default value which is 0000.

![Untitled](https://user-images.githubusercontent.com/47139708/229415314-3a63d1d9-99db-47cd-b55c-9c1b7cab6c94.png)
