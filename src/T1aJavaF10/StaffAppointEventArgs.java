
package T1aJavaF10;


public class StaffAppointEventArgs {

    private Staff staff;
    private double salary;

    public StaffAppointEventArgs(Staff st, double sal) {
        setStaff(st);
        setSalary(sal);
    }

    public void setSalary(double sal) {
        if(sal <= 0.0){
            this.salary = 0.0;
        }else{
            this.salary = sal;
        }
    }

    public void setStaff(Staff st) {
        if(st == null){
            this.staff = new Staff();
        }else{
            this.staff = st;
        }
    }

    public double getSalary() {
        return salary;
    }

    public Staff getStaff() {
        return staff;
    }

    

}
