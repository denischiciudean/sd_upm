import java.util.Scanner;
import java.util.*;

class Link {
    public String firstName;
    public String lastName;
    public Integer age;

    public Link next;

    public Link(String firstName, String lastName, Integer age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    public void display() {
        System.out.println("First name : " + firstName);
        System.out.println("Last name : " + lastName);
        System.out.println("Age : " + age);
    }

    public String toString() {
        return lastName + " " + firstName;
    }

}

class LinkList {
    public Link firstLink;
    public Link firstLinkSecondList;

    LinkList() {
        firstLink = null;
    }

    public boolean isEmpty() {
        return (firstLink == null);
    }

    /*
    Inserts
     */
    public boolean uniqueFirstAndLastName(String firstName, String lastName) {
        return firstName != lastName;
    }

    public void insertFirstLink(String firstName, String lastName, Integer age) {
        if (!uniqueFirstAndLastName(firstName, lastName)) {
            System.out.println("First name and Last name should be unique");
            return;
        }
        Link newLink = new Link(firstName, lastName, age);
        newLink.next = firstLink;
        firstLink = newLink;
    }

    public void insertLastLink(String firstName, String lastName, Integer age) {
        if (!uniqueFirstAndLastName(firstName, lastName)) {
            System.out.println("First name and Last name should be unique");
            return;
        }
        Link newLink = new Link(firstName, lastName, age);

        Link currentLink = firstLink;

        if (!isEmpty()) {
            while (currentLink.next != null) {
                currentLink = currentLink.next;
            }
            currentLink.next = newLink;
        }
    }

    public Link insertBeforeFirstName(String searchFirstName, String firstName, String lastName, Integer age) {

        if (!uniqueFirstAndLastName(firstName, lastName)) {
            System.out.println("First name and Last name should be unique");
            return null;
        }

        Link newLink = new Link(firstName, lastName, age);

        Link currentLink = firstLink;
        Link previousLink = firstLink;


        if (!isEmpty()) {

            while (currentLink.firstName != searchFirstName) {
                if (currentLink.next == null) {
                    System.out.println("Could not find the requested link");
                    return null;
                } else {
                    previousLink = currentLink;
                    currentLink = currentLink.next;
                }
            }

        } else {
            System.out.println("List is empty");
        }

        System.out.println("FOUND");

        if (currentLink == firstLink) {
            firstLink = newLink;
            firstLink.next = currentLink;
        } else {
            previousLink.next = newLink;
            newLink.next = currentLink;
        }

        return currentLink;
    }

    public Link insertAfterFirstName(String searchFirstName, String firstName, String lastName, Integer age) {

        if (!uniqueFirstAndLastName(firstName, lastName)) {
            System.out.println("First name and Last name should be unique");
            return null;
        }

        Link newLink = new Link(firstName, lastName, age);

        Link currentLink = firstLink;
        Link previousLink = firstLink;

        if (!isEmpty()) {

            while (currentLink.firstName != searchFirstName) {
                if (currentLink.next == null) {
                    System.out.println("Could not find the requested link");
                    return null;
                } else {
                    previousLink = currentLink;
                    currentLink = currentLink.next;
                }
            }

        } else {
            System.out.println("List is empty");
        }


        if (currentLink == firstLink) {
            firstLink.next = newLink;
        } else {
            newLink.next = currentLink.next;
            currentLink.next = newLink;
        }
        return currentLink;
    }

    /*
    End Inserts
     */

    /*
    Start Removing
     */
    public Link removeFirst() {
        Link linkRefrence = firstLink;
        if (!isEmpty()) {
            firstLink = firstLink.next;
        } else {
            System.out.println("Empty LinkedList");
        }
        return linkRefrence;
    }

    public Link removeLast() {
        Link currentLink = firstLink;
        Link previouseLink = firstLink;
        if (!isEmpty()) {
            while (currentLink.next != null) {
                previouseLink = currentLink;
                currentLink = currentLink.next;
            }
            previouseLink.next = null;
        }
        return previouseLink;
    }


    public Link removeLink(String firstName, String lastName) {
        Link currentLink = firstLink;
        Link previousLink = firstLink;
        while (currentLink.firstName != firstName && currentLink.lastName != lastName) {
            if (currentLink.next == null) {
                return null;
            } else {
                previousLink = currentLink;
                currentLink = currentLink.next;
            }
        }
        if (currentLink == firstLink) {
            firstLink = firstLink.next;
        } else {
            previousLink.next = currentLink.next;
        }
        return currentLink;
    }



    /*
    End Removing
     */

    public void display() {
        Link theLink = firstLink;
        while (theLink != null) {
            theLink.display();
            System.out.println("Next Link: " + theLink.next);
            System.out.println(" ");
            theLink = theLink.next;
        }
    }


    public Link findByFirstName(String firstName) {
        Link theLink = firstLink;
        if (!isEmpty()) {
            while (theLink.firstName != firstName) {
                if (theLink.next == null) {
                    return null;
                } else {
                    theLink = theLink.next;
                }
            }
        } else {

            System.out.println("Empty Linked List");
        }
        return theLink;
    }

    public LinkList searchByAge(Integer age) {
        LinkList list = new LinkList();
        Link currentLink = firstLink;
        if (!isEmpty()) {
            while (currentLink.next != null) {
                if (currentLink.age == age) {
                    if (list.isEmpty()) {
                        list.insertFirstLink(currentLink.firstName, currentLink.lastName, currentLink.age);
                    } else {
                        list.insertLastLink(currentLink.firstName, currentLink.lastName, currentLink.age);
                    }
                }
                currentLink = currentLink.next;
            }
        }
        return list;
    }


}

public class Lab {

    private Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Lab lab = new Lab();
        LinkList linkedList = new LinkList();
        // List<LinkList> lists = new ArrayList<LinkList>();
        linkedList.insertFirstLink("Chiciudean", "Denis", 20);
        linkedList.insertFirstLink("Chiciudean2", "Nicolae", 52);
        linkedList.insertFirstLink("Chiciudean1", "Patrick", 21);
        linkedList.display();
    }

    public static List cloneList(List<LinkList> lists, Integer position){
        List<LinkList> new_list =  new ArrayList<LinkList>();


        //Parse array
        for (int i = 0; i < lists.size(); i++ ) {
          LinkList inner_new_list = new LinkList();


          LinkList currentLinkList = lists.get(i);
          Link currentLink = currentLinkList.firstLink;
          System.out.println(lists.get(i).firstLink.next);

            new_list.add(inner_new_list);
        }
        return new_list;
    }
}
