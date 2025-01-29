import java.util.ArrayList;
import java.util.List;

public class Fridge {
    
    private ArrayList<String> foodItems = new ArrayList<>();
    private int balance;

    public Fridge(int initialBalance) {
        if(initialBalance < 0)
        {
            System.out.println("Eror");
            this.balance = 0;
        }
        else
        {
            this.balance = initialBalance;

        }

    }
       


    public void addFood(String item, int cost) {
        if(item == null || (item instanceof String == false))
        {
            System.out.println("Error");
            
        }
        
        else if ((this.balance - cost) >= 0 && ((this.balance - cost) <= this.balance))
        {
            foodItems.add(item);
            System.out.println("Item " + item + " has been added to the fridge.");
            this.balance = this.balance - cost;

        }
        else
        {
            System.out.println("Error");
        }
        
    }



    public void getFood(String item) {
        if(item instanceof String && (foodItems.contains(item)))
        {
            foodItems.remove(item);
            System.out.println("Item " + item + " has been removed from the fridge.");
        }
        else 
        {
            System.out.println("Error");
        }
    }


    

    public void checkStatus() {

        System.out.println("Food items:");

        if(foodItems.size() == 0)
        {
            System.out.println("(none)");
            System.out.println("Balance: €" + this.balance);
        }
        else
        {
            int i = 0;
            while(foodItems.size() > i) //getting the size of the arraylist  while(foodItems) boolean, question, why cant i do that <- for arraylist
            {  
                System.out.println(foodItems.get(i)); //getting element of arraylist, different from normal array
                ++i;
            }
            System.out.println("Balance: €" + this.balance);

        }


        
        
    }


}