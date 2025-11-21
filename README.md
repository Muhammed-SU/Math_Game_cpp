# Math Quiz Game (C++ Console Application)

This is a fully interactive **Math Quiz Game** written in **C++**, where the player answers randomly generated math questions with adjustable difficulty levels and operation types.

The game includes:
- Multiple difficulty levels (Easy, Medium, Hard, Mix)
- Different math operations (Add, Sub, Mul, Div, Mix)
- Automatic correction with right/wrong answer feedback
- Terminal color changes for correct/incorrect answers
- Final quiz results summary
- Ability to replay the quiz
- Structured code using enums, structs, and modular functions

---

## How the Game Works

### 1. Player chooses:
- **Number of questions** (1–10)
- **Difficulty level**
  - Easy → numbers 1–10  
  - Medium → numbers 10–50  
  - Hard → numbers 50–100  
  - Mix → randomly picks one of the above
- **Operation type**
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Mix → randomly picks any operation

### 2. The game generates questions automatically.

### 3. Player answers each question:
- The game checks if the answer is correct  
- Changes screen color:
  - 🟩 Green → Correct  
  - 🟥 Red → Wrong (with sound alert)

### 4. After all questions:
A results screen shows:
- Pass/Fail  
- Number of right/wrong answers  
- Difficulty level  
- Operation type  
- Total questions  
