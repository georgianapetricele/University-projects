package repo;

import model.IAnimal;



public class Repository implements IRepository{ //InMemoryRepository

    private final IAnimal[] animals;
    private int size;
    public Repository(Integer maxSize){
        this.animals = new IAnimal[maxSize];
        this.size=0;
    }

    public void addIAnimal(IAnimal animal) throws MyException {

        if(this.size == animals.length)
            throw new MyException("Array is full!");
        this.animals[this.size++]=animal;
    }

    public void removeIAnimal(Integer index) throws MyException{
        if(index<0 || index>=this.size){
            throw new MyException("Invalid position for removing!");
        }
        for(int i=index+1;i<this.size;++i)
            this.animals[i-1]=this.animals[i];
        this.size--;
    }
    public IAnimal[] getAll() throws MyException{
        if(this.size==0)
            throw new MyException("Empty list!");
        return animals;

    }



}
