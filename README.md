# Turning-an-LED-On-STM32
A simple embedded systems project demonstrating how to turn on an LED using an STM32 microcontroller.
---

## Project Overview

This project demonstrates how to turn ON an LED using register-level programming on an STM32 microcontroller without using the vendor-provided HAL (Hardware Abstraction Layer) library.

The project uses two important microcontroller drivers: RCC (Reset and Clock Control) and GPIO (General Purpose Input/Output). The RCC driver is responsible for configuring the system clock and enabling the clock for GPIO peripherals. The GPIO driver configures the selected pin as an output and controls the LED.

The LED is connected to GPIO Port A, Pin 0 (PA0). After initialization, the program configures PA0 as a push-pull output and sets it HIGH, which turns ON the LED. The LED remains ON until the board is reset or power is disconnected.

The main purpose of this project is to understand STM32 hardware registers, embedded C programming, peripheral configuration, and layered driver architecture.

This project was further reviewed as part of the Project Management course (Activity 2: GitHub-Based QA Documentation and Problem Solving). During the QA review, seven issues were identified, analysed, and assigned corrective actions using GitHub-based issue tracking and project management practices.

Project Objectives

To understand the internal working of STM32 microcontrollers.

To configure RCC and GPIO peripherals using direct register access.

To develop custom peripheral drivers without using STM32 HAL.

To configure GPIO pins as output using register-level programming.

To control an LED through GPIO Port A, Pin 0.

To understand layered architecture in embedded systems.

To identify software defects through systematic QA testing.

To use GitHub for issue tracking, version control, and project documentation.

Hardware Requirements

Component

Description

Microcontroller

STM32F4 Series

Development Board

STM32F4 Black Pill-style board / trainer kit

LED

Onboard or external LED

Power Supply

3.3V through USB-powered board

Programmer

ST-Link / SWD interface

Connecting Wires

Jumper wires, if required

Note: The exact STM32 chip part number should be confirmed from the physical board before documenting it.

Hardware Connections

Signal

STM32 Pin

Purpose

LED Positive

PA0

GPIO output

LED Ground

GND

Common ground

Power

3.3V

Board supply

SWDIO

PA13

Programming and debugging

SWCLK

PA14

Programming and debugging

The LED uses active-HIGH logic:

GPIO HIGH (1) = LED ON

GPIO LOW (0) = LED OFF

PA13 and PA14 are reserved for SWD debugging.

Software Requirements

Embedded C Programming

STM32 development environment

C Compiler

STM32F4 Reference Manual

Git and GitHub for version control and documentation

Software Architecture

The project follows a layered architecture called MCAL (Microcontroller Abstraction Layer).

The software is divided into three main layers:

1. LIB Layer

This layer contains common definitions and bit manipulation operations.

Files:

STD_TYPES.h – Defines standard data types such as u8, u16, u32 and f32.

BIT_MATH.h – Contains bit manipulation macros.

Important macros:

SET_BIT() – Sets a particular bit.

CLR_BIT() – Clears a particular bit.

TOG_BIT() – Toggles a particular bit.

GET_BIT() – Reads the value of a particular bit.

2. MCAL Layer

This layer contains peripheral drivers.

RCC Driver (Reset and Clock Control)

The RCC driver is responsible for:

Initializing the system clock.

Selecting the clock source.

Enabling peripheral clocks.

Disabling peripheral clocks.

GPIO Driver (General Purpose Input/Output)

The GPIO driver is responsible for:

Configuring GPIO pin modes.

Selecting output type.

Configuring output speed.

Setting pull-up and pull-down resistors.

Setting and clearing output pins.

Reading and toggling GPIO pins.

Configuring alternate functions.

3. Application Layer

The main.c file contains the main application logic.

It performs the following operations:

Initializes the RCC driver.

Enables the GPIOA peripheral clock.

Configures PA0 as an output.

Sets PA0 HIGH to turn ON the LED.

Keeps the LED ON using an infinite loop.

Working Principle

The project works through the following steps:

System Clock Initialization: The RCC driver initializes the system clock according to the selected configuration in RCC_cfg.h.

GPIO Clock Enable: The clock for GPIO Port A is enabled through the RCC peripheral.

GPIO Configuration: PA0 is configured as a general-purpose output pin with push-pull output type and high-speed configuration.

LED Control: The GPIO driver sets the output data register (ODR) bit corresponding to PA0.

LED ON: When PA0 becomes HIGH, the LED turns ON.

Continuous Operation: The program remains inside the infinite while(1) loop, keeping the LED ON.

Important Registers Used

Register

Function

RCC_CR

Controls the clock sources

RCC_CFGR

Configures the system clock

RCC_AHB1ENR

Enables GPIO peripheral clocks

GPIO_MODER

Configures GPIO pin mode

GPIO_OTYPER

Configures output type

GPIO_OSPEEDR

Configures output speed

GPIO_PUPDR

Configures pull-up/pull-down

GPIO_ODR

Controls GPIO output state

GPIO_BSRR

Sets or resets GPIO pins atomically

Register-Level Programming

Unlike HAL-based programming, this project directly accesses STM32 peripheral registers.

The GPIO and RCC register base addresses used in the driver are:

GPIOA Base Address: 0x40020000

RCC Base Address: 0x40023800

Direct register manipulation helps understand how the microcontroller interacts with its internal hardware peripherals.

Project Management and Quality Assurance (QA)

As part of Activity 2, the project was reviewed from a Quality Assurance perspective.

The source code was analysed to identify possible errors, reliability problems, incorrect configurations, and code-quality issues.

Seven major issues were identified:

Issue

Problem Identified

Severity

#1

Clock startup waits for HSE forever and does not verify clock switching

High

#2

Selecting PLL_CLK compiles but does not configure the PLL

Medium

#3

GPIOC clock-enable path is missing and an incorrect constant is used

Medium

#4

Reserved or invalid GPIO pins are silently ignored

Medium

#5

Non-atomic ODR writes and unsafe bit-shift macros

Medium

#6

Duplicated switch blocks, typing errors, and dead code

Low

#7

README lacks board details, pin connections, and build instructions

Low

QA Improvements Planned

Added bounded timeout handling for clock initialization.

Added error handling for unsupported PLL configuration.

Improved GPIO peripheral clock support.

Introduced validation for invalid and reserved GPIO pins.

Improved register operations using BSRR.

Corrected bit manipulation macros.

Improved code readability and removed unnecessary code.

Improved project documentation and repository organization.

Note: The fixes should be marked as completed only after implementation, testing, and merging the corresponding pull requests.

Testing and Verification

The basic LED functionality was verified using the STM32 development board.

Test Case

Expected Result

Observed Result

Power ON the board

LED should turn ON

LED ON

Press RESET

LED should turn ON again

LED ON

Configure a different GPIO pin

LED should respond to the selected pin

Additional testing required

Test invalid GPIO pins

Driver should report an error

QA test required

Test clock failure

System should handle clock failure safely

QA test required

The initial demonstration confirms that the LED turns ON successfully on PA0. Additional testing is required to verify all driver functions and QA improvements.

Repository Structure

Turning-an-LED-On-STM32/
│
├── LIB/
│   ├── STD_TYPES.h
│   └── BIT_MATH.h
│
├── MCAL/
│   ├── RCC/
│   │   ├── RCC_int.h
│   │   ├── RCC_prv.h
│   │   ├── RCC_cfg.h
│   │   └── RCC_prg.c
│   │
│   └── GPIO/
│       ├── GPIO_int.h
│       ├── GPIO_prv.h
│       ├── GPIO_cfg.h
│       └── GPIO_prg.c
│
├── docs/
│   ├── QA_checklist.md
│   └── test_log.md
│
├── .github/
│   ├── ISSUE_TEMPLATE/
│   │   └── bug_report.md
│   └── pull_request_template.md
│
├── main.c
├── .gitignore
└── README.md

GitHub Workflow

GitHub is used to manage the project and document the QA process.

The following features are used:

Issues: To report and track identified problems.

Labels: To classify bugs, enhancements, documentation, and severity.

Milestones: To divide project work into smaller targets.

Projects Board: To track tasks using Backlog, To Do, In Progress, In Review, and Done.

Branches: To work on individual fixes separately.

Pull Requests: To review changes before merging them.

Wiki: To maintain QA checklists, test logs, and root-cause analysis.

Future Enhancements

Implement a complete PLL clock configuration driver.

Add GPIO input and external interrupt support.

Improve error reporting in peripheral drivers.

Add more GPIO pin and port testing.

Improve driver reusability and maintainability.

Expand the project with additional STM32 peripherals.

Learning Outcomes

Through this project, I gained practical understanding of:

STM32 microcontroller architecture.

RCC and GPIO peripheral configuration.

Register-level embedded C programming.

Bit manipulation and register operations.

Layered driver architecture.

Debugging and software testing.

Root-cause analysis using the 5-Why technique.

GitHub-based collaboration and project management.

Credits

The original driver files contain the author attribution Nada Mamdouh (August 2025) and are based on a publicly available STM32 LED tutorial repository.

My contribution to this activity includes the QA review, issue identification, root-cause analysis, proposed fixes, test planning, project documentation, and GitHub project-management workflow.

Author

Rajpalsinh Patil

B.Tech – Electronics and Telecommunication Engineering

MIT Academy of Engineering, Pune

Course: Project Management

Project: Turning an LED ON with a Register-Level STM32 Driver (RCC + GPIO)

Project Category: Embedded Systems | STM32 | Register-Level Programming | GPIO | RCC | Embedded C | Quality Assurance
