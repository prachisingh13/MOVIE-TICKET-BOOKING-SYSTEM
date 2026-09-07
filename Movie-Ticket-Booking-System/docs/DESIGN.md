# System Design

## 1. Requirement Analysis

### Functional Requirements

- **F1:** List all movies currently playing.
- **F2:** For a chosen movie, list its shows.
- **F3:** For a chosen show, display the seat layout with AVAILABLE/BOOKED status.
- **F4:** Book one or more seats.
- **F5:** Calculate price by seat type.
- **F6:** Pay by UPI, Card or Cash. A failed payment must not confirm the booking.
- **F7:** Print a ticket containing booking ID, movie, screen, time, seat numbers and total amount.
- **F8:** Cancel a booking and make its seats available again.

### Non-Functional Requirements

1. **Modularity:** Major classes are separated into individual files.
2. **Extensibility:** New payment methods can be added through the `Payment` abstraction.
3. **Input Validation:** Invalid choices and seat numbers are handled with clear messages.
4. **Maintainability:** Responsibilities are separated using encapsulation and focused classes.

## 2. Noun–Verb Analysis

### Important Nouns

Movie, Cinema, Customer, Show, Screen, Seat, Seat Type, Booking, Payment, UPI, Card, Cash, Seat Layout, Price, Booking ID, Ticket.

### Important Verbs

Display, List, Select, Show, Book, Reject, Calculate, Pay, Confirm, Print, Cancel, Release.

## 3. Main Classes

| Class | Responsibility |
|---|---|
| Movie | Stores movie title, language and duration |
| Cinema | Manages screens |
| Screen | Manages seats |
| Seat | Stores seat number, type and price |
| Show | Connects movie, screen and show time |
| ShowSeat | Tracks seat availability for a show |
| Customer | Stores customer details |
| Booking | Manages selected seats and booking state |
| Price | Calculates booking total |
| Payment | Abstract payment interface |
| UPI | UPI payment implementation |
| Card | Card payment implementation |
| Cash | Cash payment implementation |
| Ticket | Prints ticket information |

## 4. Relationships

- Cinema **composition** Screen
- Screen **composition** Seat
- Show **aggregation** Movie
- Show **aggregation** Screen
- Show **composition** ShowSeat
- Booking **association** Customer
- Booking **aggregation** ShowSeat
- Booking **association** Payment
- Payment **inheritance** UPI
- Payment **inheritance** Card
- Payment **inheritance** Cash
- Booking **association** Price
- Booking **association** Ticket

## 5. SOLID Mapping

### S — Single Responsibility
Each class has a focused responsibility.

### O — Open/Closed
Payment can be extended with a new subclass without changing existing booking logic.

### L — Liskov Substitution
UPI, Card and Cash can be used through the `Payment` abstraction.

### I — Interface Segregation
The payment abstraction exposes only the required `pay()` operation.

### D — Dependency Inversion
Booking/payment workflow can depend on the `Payment` abstraction rather than concrete payment types.

## 6. Booking State

```text
Pending → Confirmed
   │
   ├── Payment Failed → Failed
   │
   └── Cancelled → Seats Released
```
