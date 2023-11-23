package controller;

import model.IAnimal;
import repo.IRepository;
import repo.MyException;

//controller
public class Controller {
    private IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public void add(IAnimal animal) throws MyException{
            repo.addIAnimal(animal);
    }

    public void remove(Integer index) throws MyException{
        repo.removeIAnimal(index);
    }

    public IAnimal[] getAll() throws MyException{
        return repo.getAll();
    }

    public IAnimal[] getAllFilteredByWeight(Integer weight) throws MyException {
        IAnimal[] animals=repo.getAll();
        IAnimal[] filteredAnimals = new IAnimal[animals.length];
        int size=0;
        for(IAnimal animal:animals)
        {
            if(animal==null)
                break;
            if(animal.getWeight().compareTo(weight)>0)
                filteredAnimals[size++]=animal;
        }
        return filteredAnimals;



    }
}
