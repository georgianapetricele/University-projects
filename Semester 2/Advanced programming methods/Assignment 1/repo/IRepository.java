package repo;

import model.IAnimal;

public interface IRepository {
    //IFruit in loc
    public void addIAnimal(IAnimal animal) throws MyException;
    public void removeIAnimal(Integer index) throws MyException;
    public IAnimal[] getAll() throws MyException;
}

