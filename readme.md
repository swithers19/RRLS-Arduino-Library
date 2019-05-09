# Library Purpose

The learning device library helps report students implementation to the rest of the system. This was achieved by a library which serves two functions:
- Collecting a snapshot of the codes operation
- Communicating this information to the debugging shield

The benefit of implementing this was the opportunity to make the code more readable with logical function names. One downside is the need to implement peripherals into the library, but there was no foreseeable way to prevent this.


## UML Class Diagram
Below is the relationship between peripherals and the peripheral object, with the goal to abstract away from each individual peripheral to simplify adding peripherals in the future.

![UML Diagram of Peripherals](https://raw.githubusercontent.com/swithers19/RRLS-Arduino-Library/master/docs/UML-Class-Diagram.png)