Paste the stm32f103c8t6-board.step file to
C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\DATA\MCAD

Paste BLUEPILL.IDX, BLUEPILL.LIB y LICENSE files to
C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\DATA\LIBRARY
This enables 3D view of components in Proteus.

After that, go to Schematic and change the PCB Package to
stm32f103 BOARD (Needs to be done after you create the PCB).
It doesn't need to change the STM PCB Package to that, but
it will at least create an entry in the PCB Layout that
magically does work in the 3D Visualizer.
