#include <iostream>
#include <cmath> 
#include <string>

using namespace std;

enum enQuetionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

string GetQuestionLevelTest(enQuetionLevel QuestLevel)
{
    string arrQuestLevelText[4] = { "Easy","Med","Hard","Mix" };
    return arrQuestLevelText[QuestLevel - 1];
}

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void ScreenColor(bool Right)
{
    if (Right)
        system("color 2F");
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

short ReadHowManyQuestions()
{
    short NumberOfQuestion;
    do
    {
        cout << "How many Questions do you want to answer ?\n";
        cout << "-> ";
        cin >> NumberOfQuestion;
    } while (NumberOfQuestion < 1 || NumberOfQuestion>10);

    return NumberOfQuestion;
}

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "*";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

enQuetionLevel ReadQuestionLevel()
{
    short QuestLevel = 0;

    do
    {
        cout << "Enter Question level [1]Easy [2]Medium [3]Hard [4]Mix ?\n";
        cout << "-> ";
        cin >> QuestLevel;

    } while (QuestLevel < 1 || QuestLevel > 4);

    return (enQuetionLevel)QuestLevel;
}

enOperationType ReadOperationType()
{
    short OpType;

    do
    {
        cout << "Enter operation type [1]Additio [2]Subtraction [3]Division [4]Multiplicatoin [5]Mix ?\n";
        cout << "-> ";
        cin >> OpType;

    } while (OpType < 1 || OpType > 5);

    return (enOperationType)OpType;
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enQuetionLevel QuestLevel;
    enOperationType OperatoinType;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResults = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestion;
    enQuetionLevel QuestionLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NubmerOfRightAnswers = 0;
    bool isPass = false;
};

int SimpleCalculator(int Num1, int Num2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Num1 + Num2;
    case enOperationType::Sub:
        return Num1 - Num2;
    case enOperationType::Mul:
        return Num1 * Num2;
    case enOperationType::Div:
        return (Num2 == 0) ? 0 : Num1 / Num2;
    default:
        Num1 + Num2;
    }
}

enOperationType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}

stQuestion GenerateQuestion(enQuetionLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuetionLevel::Mix)
    {
        QuestionLevel = (enQuetionLevel)RandomNumber(1, 3);
    }

    if (OpType == enOperationType::MixOp)
    {
        OpType = GetRandomOperationType();
    }

    Question.OperatoinType = OpType;

    switch (QuestionLevel)
    {
    case enQuetionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatoinType);

        Question.QuestLevel = QuestionLevel;

        return Question;

    case enQuetionLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatoinType);

        Question.QuestLevel = QuestionLevel;

        return Question;

    case enQuetionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatoinType);

        Question.QuestLevel = QuestionLevel;

        return Question;
    }

    return Question;

}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpType);
    }
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperatoinType);
    cout << "\n------------" << endl;
}

void QurrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResults = false;
        Quizz.NumberOfWrongAnswers++;

        cout << "Wrong answer :-( \n";
        cout << "The right answer is : ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResults = true;
        Quizz.NubmerOfRightAnswers++;

        cout << "Right answer :-) \n";
    }
    cout << endl;

    ScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResults);

}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestion; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        QurrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NubmerOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string FinalResultsText(bool Pass)
{
    if (Pass)
        return "Pass :-)";
    else
        return "Fail :-(";
}

void PrintQuizzResults(stQuizz& Quizz)
{
    cout << "\n";
    cout << "------------------------\n\n";
    cout << "Final results is :" << FinalResultsText(Quizz.isPass);
    cout << "\n-------------------------\n\n";
    cout << "Number of questions: " << Quizz.NumberOfQuestion << endl;
    cout << "Questions level: " << GetQuestionLevelTest(Quizz.QuestionLevel) << endl;
    cout << "Operation type: " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of right answers: " << Quizz.NubmerOfRightAnswers << endl;
    cout << "Number of wrong answers: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "----------------------------\n";
}

void PlayMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestion = ReadHowManyQuestions();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OpType = ReadOperationType();

    GenerateQuizzQuestion(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayMathGame();

        cout << endl << "Do you want to play again: Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}
