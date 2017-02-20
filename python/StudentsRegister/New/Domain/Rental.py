'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

class Rental:
    
    def __init__(self, student, assignment, price):
        
        self.__student = student
        self.__assignment = assignment
        self.__price = price
        
    @property
    def assignment(self):
        return self.__assignment
    
    @property
    def student(self):
        return self.__student
    
    @property
    def price(self):
        return self.__price
    
    def __str__(self):
        return "Assignment {0} for student {1}".format(self.assignment, self.student)

    
    def __repr__(self):
    
        return str(self)
    
    def __eq__(self, other):
        return type(self) == type(other) and self.student.id_student == other.student.id_student \
                                         and self.car.id_assignment == other.car.id_assignment
    
