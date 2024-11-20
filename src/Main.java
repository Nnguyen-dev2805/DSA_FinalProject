import model.PolishNational;

import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String bt;
        System.out.print("Nhap bieu thuc Infix: ");
        bt=sc.nextLine();
        PolishNational polishNational = new PolishNational(bt);
        String posfix= polishNational.InfixtoPosfix();
        System.out.println(polishNational.getInfix());
        System.out.println("Posfix: "+posfix);
        String Result=polishNational.ResultPosfix(posfix);
        System.out.println("Result: "+Result);
    }
}