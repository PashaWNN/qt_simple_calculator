#include <QDebug>
#include <math.h>

struct Expression {
    Expression(QString token) : token(token) {}
    Expression(QString token, Expression a) : token(token), args{ a } {}
    Expression(QString token, Expression a, Expression b) : token(token), args{ a, b } {}

    QString token;
    QVector<Expression> args;
};

class Parser {
public:
    Parser(QString input): input(input) {}
    Expression parse();
private:
    QString parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);
    QString input;
    int i = 0;
};

QString Parser::parse_token() {
    while (input[i]==' ') ++i;
    if (input[i].isDigit()) {
        QString number;
        while (input[i].isDigit() || input[i] == '.') number.push_back(input[i++]);
        return number;
    }

    static const QString tokens[] =
    { "e+", "e-", "+", "-", "*", "^", "/", "sin", "cos", "exp", "tan", "ln", "log", "(", ")" };
    for (auto& t: tokens) {
        if (input.mid(i, t.size()) == t) {

            i += t.size();
            return t;
        }
    }
    return "";
}

Expression Parser::parse_simple_expression() {
    auto token = parse_token();
    if (token.isEmpty()) throw 10;

    if (token == "(") {
        auto result = parse();
        if (parse_token() != ")") throw 20;
        return result;
    }
    if (token[0].isDigit())
        return Expression(token);
    return Expression(token, parse_simple_expression());
}

int get_priority(const QString binary_op) {
        if (binary_op == "+") return 1;
        if (binary_op == "-") return 1;
        if (binary_op == "*") return 2;
        if (binary_op == "/") return 2;
        if (binary_op == "^") return 3;
        if (binary_op == "e+") return 4;
        if (binary_op == "e-") return 4;
        return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {
    auto left_expr = parse_simple_expression();

    for (;;) {
        auto op = parse_token();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            i -= op.size();
            return left_expr;
        }

        auto right_expr = parse_binary_expression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::parse() {
    return parse_binary_expression(0);
}

double eval(const Expression& e) {
    switch (e.args.size()) {
    case 2: {
        auto a = eval(e.args[0]);
        auto b = eval(e.args[1]);
        if (e.token == "e+") return QString(QString::number(a) + "e+" + QString::number(b)).toDouble();
        if (e.token == "e-") return QString(QString::number(a) + "e-" + QString::number(b)).toDouble();
        if (e.token == "+") return a + b;
        if (e.token == "-") return a - b;
        if (e.token == "*") return a * b;
        if (e.token == "/") return a / b;
        if (e.token == "^") return pow(a, b);
        throw 30;
    }
    case 1: {
        auto a = eval(e.args[0]);
        if (e.token == "+") return +a;
        if (e.token == "-") return -a;
        if (e.token == "sin") return sin(a);
        if (e.token == "cos") return cos(a);
        if (e.token == "tan") return tan(a);
        if (e.token == "ln") return log10(a);
        if (e.token == "log") return log(a);
        if (e.token == "exp") return exp(a);
        throw 40;
    }
    case 0: {
        return e.token.toDouble();
    }
        throw 50;
    }
}


QString Calculate(QString expression) {
    //TODO: Calculate
    qDebug() << QString("Calculating '%1'...").arg(expression);
    Parser p(expression);
    auto result = eval(p.parse());
    return QString::number(result);
}

QString add_symbol(QString expression, QString symbol) {
    return expression+symbol;
}
