public abstract class User {
    private String name;
    private String user;
    private String pass;

    public User(String user, String pass, String name) {
        this.user = user;
        this.pass = pass;
        this.name = name;
    }

    public String getUser() {
        return this.user;
    }

    public String getUserName() {
        return this.name;
    }

    public String getPass() {
        return this.pass;
    }

    public void setUser(String user) {
        this.user = user;
        return;
    }

    public void setPass(String pass) {
        this.pass = pass;
        return;
    }

    public void setName(String name) {
        this.name = name;
        return;
    }

}
