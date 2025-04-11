**Mechanism Used**

I have chosen to use a **hybrid mechanism** for the stair-climbing
robot, as it offers better adaptability for steps of varying heights.
The design combines both **wheels and articulated (armed) legs** to
climb stairs more effectively.

The overall structure resembles an **RC car**, but with a unique twist:
the **front wheels are flexibly movable** through an arm mechanism to
help with stair climbing.

**Design Explanation**

The robot has a total of **6 wheels**, and the main climbing is done
using the **front four wheels**. For clarity, I'll describe the
mechanism for **one side** of the robot:

-   The **first two wheels** on one side are connected by an **L-shaped
    arm**.

-   The **length of the L-arm** defines the **maximum step height** the
    robot can climb.

**Climbing Process (One Side):**

1.  **Approach the Step:\
    **The first wheel comes in contact with the stair and starts
    climbing.\
    The **middle and rear wheels push** the robot forward during this.

2.  **Middle Wheel Climb:\
    **Once the first wheel has climbed, the **middle wheel starts to
    ascend**.

The front wheels **pull**, while the back wheel **pushes**.

3.**Top Pull:\
       ** With both the front wheels on top of the stair, they **pull
the entire robot forward**,                completing the climb.

A PDF named Climbmech.pdf has  been attached in the repository to depict
the climbing mechanism.

** Weight Distribution**

-   The **major weight contributors** are the **structural frame and
    battery**.

-   Other components (sensors, controllers, wiring) are relatively light
    and don't significantly affect the center of mass.

-   The **battery is placed toward the front** to:

-   Keep the center of mass forward.

-   Prevent the robot from **toppling backward** during stair climbing.

** Components List**

  -------------------------------------------------------------------------------
  **Component**     **Quantity**   **Reason for Selection**
  ----------------- -------------- ----------------------------------------------
  3D Printed Frame                 Lightweight and customizable

  Johnson Motors    6              High torque, suitable for climbing, speed is
  (100 RPM)                        not a priority

  Arduino Uno/Mega  1              Easy programming and integration, enough I/O
                                   for sensors and drivers

  IBT-2 Motor       2              Capable of handling high currents (\~15A)
  Drivers                          

  Li-Po Battery (3S 1              Lightweight and provides high discharge
  12V)                             current for motors

  Ultrasonic        2              One at the top and one at wheel axle to
  Sensors                          differentiate between stairs and obstacles

  Servo Motors      2              For operating any flexible or assistive
                                   mechanisms as needed
  -------------------------------------------------------------------------------

** Control Strategy**

-   **Ultrasonic Sensor Placement:\
    **One sensor is placed **on top**, and the other near the **axle of
    the front wheels**.

-   If both sensors detect a **significant difference in distance**, it
    likely indicates a stair.

-   The bot then proceeds to **initiate the climbing sequence**.

**Battery & Power Calculation**

**➤ Motor Requirements:**

Each **Johnson 100 RPM motor** (under load):

-   **Voltage:** 12V

-   **Current (max):** 1.5A

-   **Stall Current:** \~2.5A

For **6 motors**:

-   **Normal Operation:** 6 × 1.5A = **9A**

-   **Stall Condition:** 6 × 2.5A = **15**

**➤ Battery Specifications:**

-   **Type:** LiPo

-   **Rating:** 3S, 2200mAh, 25C

-   **Current Capacity:** 2.2Ah × 25C = **55A max output**

** Why L298N Is Not Used(The most popular one in the club :))**

-   The **L298N motor driver** cannot handle high current (limited to
    \~2A per channel).

-   With total current peaking at **15A**, the **IBT-2** is chosen as
    it's more suitable for high-torque applications like stair climbing.

![](vertopal_5a685bd293694b138993ce3b52446504/media/image1.png){width="7.25in"
height="4.691666666666666in"}

![](vertopal_5a685bd293694b138993ce3b52446504/media/image4.png){width="7.025in"
height="2.375in"}
