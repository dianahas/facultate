'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

class Console:
    
    def __init__(self, ctrl_undo, ctrl_assignment, ctrl_student, ctrl_rental):
        
        self.__ctrl_undo = ctrl_undo
        
        self.__ctrl_assignment = ctrl_assignment
        self.__ctrl_student = ctrl_student
        self.__ctrl_rental = ctrl_rental
        
        
    def show(self):
        
        while True:
            print("1. Add assignment")
            print("2. Update assignment")
            print("3. Delete assignment")
            print("4. Add student")
            print("5. Update student")
            print("6. Delete student")
            print("7. Show students")
            print("8. Show assignments")
            print("9. Add rental")
            print("10. Delete rental")
            print("11. Show rentals")
            print("12. Undo (ONLY WORKS FOR CASCADE DELETES)")
            print("13. Redo (SAME)")

            print("0. Exit")
            
            option = input("Option: ")
            
            if option == "1":
                self.__add_assignment()
            elif option == "2":
                self.__update_assignment()
            elif option == "3":
                self.__delete_assignment()
            elif option == "4":
                self.__add_student()
            elif option == "5":
                self.__update_students()
               
            elif option == "6":
                self.__delete_students()
            elif option == "7":
                self.__show_students()
            elif option == "8":
                self.__show_assignment()
            elif option == "9":
                self.__add_rental()
            elif option == "10":
                self.__delete_rental()
            elif option == "11":
                self.__show_rentals()
            elif option == "12":
                self.__undo()
            elif option == "13":
                self.__redo()
            elif option == "0":
                break
            else:
                print("Invalid option, please try again!")
                
    def __add_assignment(self):
        
        while True:
            
            try:
                id = input("ID: ")
                description = input("description: ")
                
                self.__ctrl_assignment.add(id, description)
            
                break
            except KeyError as ke:
                print(ke)
                
    def __add_student(self):
        
        while True:
        
            try:
                id = input("ID: ")
                name = input("name: ")
                group = input ("group: ")
                
                self.__ctrl_student.add(id, name,group)
                
                break
            except KeyError as ke:
                print(ke)
                
    def __show_assignment(self):
        
        print(self.__ctrl_assignment.get_all())
        
    def __show_students(self):
        
        print(self.__ctrl_student.get_all())
        
    def __update_assignment(self):
        
        while True:
            
            try:
                id = input("ID: ")
                description = input("description: ")
                
                self.__ctrl_assignment.update(id, description)
            
                break
            except KeyError as ke:
                print(ke)
                
    def __delete_assignment(self):
        
        while True:
            
            try:
                id = input("ID to delete: ")
                
                self.__ctrl_assignment.delete(id)
                
                break
            except KeyError as ke:
                print(ke)
        
    def __update_students(self):
        
        while True:
        
            try:
                id = input("ID: ")
                name = input("name: ")
                group= input("group: ")
                
                self.__ctrl_student.update(id,name,group)
                self.__ctrl_rental.update_by_student(id)
                
                
                
                break
            except KeyError as ke:
                print(ke)
                
    def __delete_students(self):
        
        while True:
            
            try:
                id = input("ID to delete: ")
                
                self.__ctrl_student.delete(id)
                
                break
            except KeyError as ke:
                print(ke)
        
    def __add_rental(self):
        
        while True:
            
            #try:
                id_client = input("ID Client: ")
                id_car = input("ID Car: ")
                price = input("Price: ")
                
                self.__ctrl_rental.add(id_client, id_car, price)
                
                break
            #except KeyError as ke:
            #    print(ke)
            #except ValueError as ve:
            #    print(ve)
                
    def __delete_rental(self):
        
        while True:
            
            try:
                id_client = input("ID of the client: ")
                id_car = input("ID of the car: ")
                
                self.__ctrl_rental.delete(id_client, id_car)
                
                break
            except KeyError as ke:
                print(ke)
    def __updateByStudent_rental(self,id_student):
        
        self.__ctrl_rental.updateByStudent(id_student)
    def __show_rentals(self):
        
        print(self.__ctrl_rental.get_all())
        
    def __undo(self):
        
        self.__ctrl_undo.undo()
        
    def __redo(self):
        
        self.__ctrl_undo.redo()