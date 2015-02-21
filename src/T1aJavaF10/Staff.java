package T1aJavaF10;

import java.io.Serializable;

public class Staff implements Serializable{

    private String workAt;
    private String name;
    private double salary;


    public Staff() {
        this("", "", 0.0);
    }

    public Staff(String workAtStr, String nameStr, double salaryD) {
        setWorkAt(workAtStr);
        setName(nameStr);
        setSalary(salaryD);
    }

    public Staff(Staff st) {
        this(st.getWorkAt(),st.getName(), st.getSalary());
    }

    public void setName(String nameStr) {
        if (nameStr == null) {
            this.name = "";
        } else {
            this.name = nameStr;
        }

    }

    public void setSalary(double salaryD) {
        if (salaryD <= 0.0) {
            this.salary = 0.0;
        } else {
            this.salary = salaryD;
        }
    }

    public void setWorkAt(String workAtStr) {
        if (workAtStr == null) {
            this.workAt = "";
        } else {
            this.workAt = workAtStr;
        }
    }

    public String getName() {
        if (name.startsWith("CS@")) {

        }
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public String getWorkAt() {
        return workAt;
    }

    public String toString() {

        return String.format("Name is %s, work at %s, salary is %.2f", getName(), getWorkAt(), getSalary());
    }
}
