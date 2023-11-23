package view;
// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import model.*;
import controller.Controller;
import repo.*;

/*
4. La o ferma se cresc pasari, vaci si porci.
Sa se afiseze toate animalele care au greutatea
mai mare decit 3kg.
 */

public class View {

    static IRepository repo = new Repository(10);
    static Controller controller = new Controller(repo);

    public static void main(String[] args) {
        IAnimal bird1 = new Bird("Coco", 5);
        IAnimal bird2 = new Bird("Tiny", 1);
        IAnimal cow1 = new Cow("Lola", 20);
        IAnimal cow2 = new Cow("Milka", 2);
        IAnimal pig1 = new Pig("Pig1", 100);
        IAnimal pig2 = new Pig("Pig2", 2);


        try {
            controller.add(bird1);
            controller.add(bird2);
            controller.add(cow1);
            controller.add(cow2);
            controller.add(pig1);
            controller.add(pig2);
            controller.remove(2);

                System.out.println("The array after adding/removing animals:");
                for (IAnimal animal : controller.getAll())
                    if (animal != null)
                        System.out.println(animal.toString());
        } catch (MyException e1) {
                System.out.println(e1.getMessage());
            }

        try {
                    System.out.println("The array after filtering by weight:");
                    IAnimal[] filteredArray = controller.getAllFilteredByWeight(3);
                    for (IAnimal animal : filteredArray)
                        if (animal != null)
                            System.out.println(animal.toString());

        } catch (MyException e2) {
                    System.out.println(e2.getMessage());
                }
            }
}
