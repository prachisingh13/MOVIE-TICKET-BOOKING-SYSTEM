# Movie Ticket Booking System 🎬

A modular **C++ console-based Movie Ticket Booking System** designed for a single cinema.  
The project follows the requirements and object-oriented design of the TCS-504 System Design assignment.

## Student Details

- **Name:** PRACHI SINGH
- **Section:** G1
- **Roll No.:** 26
- **Subject:** System Design (TCS-504)

## Features

- List currently playing movies
- Display shows for a selected movie
- Display seat layout and availability
- Book one or more seats
- Calculate price by seat type
- Pay using **UPI, Card, or Cash**
- Prevent confirmation when payment fails
- Release seats automatically after failed payment
- Print ticket with booking details
- Cancel a booking and release seats
- Input validation for menu, movie, show, seat and payment choices

## Movies

| Movie | Language | Duration |
|---|---|---:|
| Harry Potter : The Prisoner of Azkaban | English | 142 min |
| 12th Fail | Hindi | 147 min |
| Mission Mangal | Hindi | 127 min |

## Seat Pricing

| Seat Type | Price |
|---|---:|
| Silver | ₹180 |
| Gold | ₹300 |
| Platinum | ₹450 |

## Project Structure

```text
Movie-Ticket-Booking-System/
├── include/
│   ├── Booking.h
│   ├── Cinema.h
│   ├── Customer.h
│   ├── Movie.h
│   ├── Payment.h
│   ├── Price.h
│   ├── Screen.h
│   ├── Seat.h
│   ├── Show.h
│   ├── Ticket.h
│   └── Types.h
├── src/
│   ├── Booking.cpp
│   ├── Cinema.cpp
│   ├── Customer.cpp
│   ├── Movie.cpp
│   ├── Payment.cpp
│   ├── Price.cpp
│   ├── Screen.cpp
│   ├── Seat.cpp
│   ├── Show.cpp
│   ├── Ticket.cpp
│   └── main.cpp
├── diagrams/
│   ├── UML_Class_Diagram.png
│   └── Sequence_Diagram_Horizontal.png
├── docs/
│   └── DESIGN.md
├── examples/
│   └── sample-output.txt
├── .gitignore
├── CMakeLists.txt
├── Makefile
└── README.md
```

## Requirements

- C++17 or newer
- CMake 3.15+ (optional)
- GNU g++ / Clang++ / MSVC

## Run with g++

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o movie_booking
./movie_booking
```

On Windows:

```powershell
g++ -std=c++17 -Iinclude src/*.cpp -o movie_booking.exe
.\movie_booking.exe
```

## Run with Make

```bash
make
./movie_booking
```

Clean:

```bash
make clean
```

## Run with CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Then run the generated executable.

## Design Highlights

### Modularity
Each major class is separated into its own header/source file.

### Abstraction and Polymorphism
`Payment` is an abstract base class. `UPI`, `Card`, and `Cash` implement the `pay()` operation.

### Encapsulation
Data members are private and accessed through public methods.

### Separation of Responsibilities

- `Movie` → movie information
- `Cinema` → screens
- `Screen` → seats
- `Show` → movie/show timing and show seats
- `Booking` → booking state and selected seats
- `Price` → total price calculation
- `Payment` → payment abstraction
- `Ticket` → ticket printing
- `Customer` → customer information

## Payment Failure Behaviour

```text
Select Seats
     ↓
Calculate Total
     ↓
Choose Payment
     ↓
Payment Failed?
   ↙       ↘
 YES       NO
 ↓          ↓
Release    Confirm
Seats      Booking
 ↓          ↓
Booking    Print
Failed     Ticket
```

## GitHub Upload

Create a repository on GitHub and upload this folder.

```bash
git init
git add .
git commit -m "Initial movie ticket booking system"
git branch -M main
git remote add origin YOUR_REPOSITORY_URL
git push -u origin main
```

> Replace `YOUR_REPOSITORY_URL` with your GitHub repository URL.

## Academic Note

This is a console-based academic project. Payment operations are simulated and do not connect to real UPI/card/cash payment systems.
