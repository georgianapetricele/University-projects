package model;


public class Cow implements IAnimal{

    private Integer weight;
    private String name;
    public Cow(String name,Integer weight) {
        this.name=name;
       this.weight=weight;
    }

    public String toString(){
        return "Cow " + this.name+": "+this.weight;
    }

    public Integer getWeight(){
        return this.weight;
    }

    public String getName(){
        return this.name;
    }

    public void setWeight(Integer weight){
        this.weight = weight;
    }

    public void setName(String name){
        this.name = name;
    }


}