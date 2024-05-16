import java.util.Date;

public class Customer extends User {
    private String NIF;
    private String mail;
    private String company;

    public Customer(String NIF, String mail, String company)
    {
        super(NIF, mail, company);
    }

    public String getNIF()
    {
        return this.NIF;
    }

    public String getMail()
    {
        return this.mail;
    }

    public String getCompany()
    {
        return this.company;
    }


    public void setNIF(String NIF)
    {
        this.NIF = NIF;
    }

    public void setMail(String mail)
    {   
        this.mail = mail;
    }

    public void setCompany(String company)
    {
        this.company = company;
    }


}