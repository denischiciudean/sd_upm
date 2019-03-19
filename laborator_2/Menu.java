import java.util.Scanner;

public class Menu {


    public static void main(String[] args) {

        Integer menu, submenu;
        menu = submenu = 100;

        Scanner sc = new Scanner(System.in);

        while (menu != 0) {

            System.out.println("Introduceti o varianta de la 0-7:");
            System.out.println("0.) Iesire Program");
            System.out.println("1.) Initializare LSI");
            System.out.println("2.) Inserare LSI");
            System.out.println("4.) Sterge LSI");
            System.out.println("5.) Traversae LSI");
            System.out.println("6.) Actualizare");
            System.out.println("7.) Eliberare LSI");

            menu = sc.nextInt();

            switch (menu) {
                case 0:
                    System.out.println("Apelul functiei de initializare");
                    break;

                case 1:
                    System.out.println("1");

                    break;

                case 2:
                    System.out.println("1");

                    break;

                case 3:
                    System.out.println("1");

                    break;

                case 4:
                    System.out.println("1");

                    break;

                case 5:
                    System.out.println("1");

                    break;

                case 6:
                    System.out.println("1");

                    break;

                case 7:
                    System.out.println("1");

                    break;
            }
        }

    }
}
