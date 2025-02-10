import java.util.Scanner;
import java.util.*;

//construction overloading: permette di avere modi diversi di creare un instance di un ogetto
/* per esempio se faccio un 
class cat():
__init__(x, y, z):
avro bisogno di 3 parametri per fare un ogetto di classe cat
ma se faccio un construction overload e metto anche __init__(x,y):
un ogetto di tipo gatto puo essere initialized sia con 2 che con 3 parametri
(non vera sintassi di python ma il concetto rimane)

method overload e come sai gia */

public class Product{
	private String productName;
	private int price;
	private boolean inStock;
	private List<String> tags;



	public Product(){
		this.productName = "Unknown";
		this.price = 0;
		this.inStock = false;
		this.tags = new ArrayList<>();
	}


	public Product(String pn){
		if(pn == null)
		{
			this.productName = "Unknown";
		}
		else
		{
			this.productName = pn;

		}
		
		this.price = 0;
		this.inStock = false;
		this.tags = new ArrayList<>();

	}





//deep copy, dont understand
	public Product(Product obj)
	{
		this(obj.productName, obj.price, obj.inStock, new ArrayList<String>(obj.tags));
		// this.productName = obj.productName;
		// this.price = obj.price;
		// this.inStock = obj.inStock;
		// this.tags = new ArrayList<String>(obj.tags);

	}



	public Product(String pn, int p){
	    if(pn == null)
		{
			this.productName = "Unknown";
		}
		else
		{
			this.productName = pn;

		}

		if(p < 0)
		{
			this.price = 0;
		}
		else
		{
			this.price = p;
		}
		
		this.inStock = false;
		this.tags = new ArrayList<>();

	}
	public Product (String pn, int p, List<String> item){
		if(pn == null)
		{
			this.productName = "Unknown";
		}
		else
		{
			this.productName = pn;

		}

		if(p < 0)
		{
			this.price = 0;
		}
		else
		{
			this.price = p;
		}	
		this.inStock = false;

		if(item == null)
		{
			this.tags = new ArrayList<>();

		}
		else
		{
			this.tags = item;
		}
		
	}

	public Product (String pn, int p, boolean iS){
		if(pn == null)
		{
			this.productName = "Unknown";
		}
		else
		{
			this.productName = pn;

		}

		if(p < 0)
		{
			this.price = 0;
		}
		else
		{
			this.price = p;
		}
		this.inStock = iS;
		this.tags = new ArrayList<>();
	}

	public Product(String pn, int p, boolean iS, List<String> item){

		if(pn == null)
		{
			this.productName = "Unknown";
		}
		else
		{
			this.productName = pn;

		}

		if(p < 0)
		{
			this.price = 0;
		}
		else
		{
			this.price = p;
		}
		this.inStock = iS;
		if(item == null)
		{
			this.tags = new ArrayList<>();

		}
		else
		{
			this.tags = new ArrayList<String>(item);
		}

	}



	public List<String> getTags() //returing list , what is difference from arraylist dk
	{

        return tags;
	}


	public void addTag(String Tag)
	{
			if(Tag instanceof String == true)
         {
            tags.add(Tag);             
        }
         else
         {
             System.out.println("Error");
         }
        
}

@Override //doouble check what it does
    public String toString() { //similar to __str__ in python maybe
        return "Product{" +
                "productName='" + productName + '\'' +
                ", price=" + price +
                ", inStock=" + inStock +
                ", tags=" + tags +
                '}';
    }


}

