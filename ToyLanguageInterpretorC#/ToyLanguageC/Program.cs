using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.controller;
using ToyLanguageC.model;
using ToyLanguageC.repository;
using ToyLanguageC.utils;
using ToyLanguageC.view;

namespace ToyLanguageC
{
    class Program
    {
        static void Main(string[] args)
        {
            Statement statement = new CompStmt(
                new AssignStmt("v", new ConstExpr(2)),
                new PrintStmt(new VarExpr("v")));

            Statement st2 = new CompStmt(
                        new AssignStmt(
                                "a",
                                new ArithExpr('+',
                                        new ConstExpr(2),
                                        new ArithExpr('*',
                                                new ConstExpr(3),
                                                new ConstExpr(5)
                                        )
                                        )),
                        new CompStmt(
                                new AssignStmt(
                                        "b",
                                        new ArithExpr('+',
                                                new VarExpr("a"),
                                                new ConstExpr(1)
                                                )),
                                new PrintStmt(new VarExpr("b"))));

            Statement st3 = new CompStmt(
                        new AssignStmt("v", new ArithExpr('/',
                                                new VarExpr("2"),
                                                new ConstExpr(0)
                                                )),
                        new PrintStmt(new VarExpr("v")));

            Statement st4 = new CompStmt(
                        new OpenFileStmt("var_f", "test.in"),
                        new CompStmt(
                                new ReadFileStmt(new VarExpr("var_f"), "var_c"),
                                new CompStmt(
                                        new PrintStmt(new VarExpr("var_c")),
                                        new CompStmt(
                                                new IfStmt(
                                                        new VarExpr("var_c"),
                                                        new CompStmt(
                                                                new ReadFileStmt(new VarExpr("var_f"), "var_c"),
                                                                new PrintStmt(new VarExpr("var_c"))
                                                        ),
                                                        new PrintStmt(new ConstExpr(0))
                                                ),
                                                new CloseFileStmt(new VarExpr("var_f")))
                                )
                        )
                );

            ProgState prg8 = new ProgState(new SymbolTable<String, int>(), new ExeStack<Statement>(), new Output<int>(), new FileTable<int,FileData>(), statement);
            IRepository repo8 = new Repository(prg8,"file88.txt");
            Controller ctr8 = new Controller(repo8);

            ProgState prg2 = new ProgState(new SymbolTable<String, int>(), new ExeStack<Statement>(), new Output<int>(), new FileTable<int, FileData>(), st2);
            IRepository repo2 = new Repository(prg2, "file1.txt");
            Controller ctr2 = new Controller(repo2);

            ProgState prg3 = new ProgState(new SymbolTable<String, int>(), new ExeStack<Statement>(), new Output<int>(), new FileTable<int, FileData>(), st3);
            IRepository repo3 = new Repository(prg3, "file2.txt");
            Controller ctr3 = new Controller(repo3);

            ProgState prg4 = new ProgState(new SymbolTable<String, int>(), new ExeStack<Statement>(), new Output<int>(), new FileTable<int, FileData>(), st4);
            IRepository repo4 = new Repository(prg4, "file3.txt");
            Controller ctr4 = new Controller(repo4);

            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit"));
            menu.addCommand(new AllStepCommand("10", statement.toString(), ctr8));
            menu.addCommand(new AllStepCommand("2", st2.toString(), ctr2));
            menu.addCommand(new AllStepCommand("3", st3.toString(), ctr3));
            menu.addCommand(new AllStepCommand("4", st4.toString(), ctr4));
            menu.show();
        }
    }
}
