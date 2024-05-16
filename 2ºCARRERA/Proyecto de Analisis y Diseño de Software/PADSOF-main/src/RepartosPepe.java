//si está mal algo lo ha hecho el miki

import java.util.List;
import java.util.ArrayList;


public class RepartosPepe {
   
    private List<User> users;
    private List<Package> packages;

    public RepartosPepe() {
        this.users = new ArrayList<User>();
        this.packages = new ArrayList<Package>();
    }

    public List<User> getUsers() {
        return this.users;
    }
    public List<Package> getPackage() {
        return this.packages;
    }

    public void setUsers(List<User> users) {
        this.users = users;
        return;
    }
    public void setPackages(List<Package> packages) {
        this.packages = packages;
        return;
    }

    public void addUser(User user) {
        this.users.add(user);
        return;
    }
    
    public void addPackage(Package packag) {
        this.packages.add(packag);
    }


    
}   









