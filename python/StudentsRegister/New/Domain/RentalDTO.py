'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

class RentalDTO:
    
    def __init__(self, id_student, id_assignment, price):
        
        self.__id_student = id_student
        self.__id_assignment = id_assignment
        self.__price = price
        
    @property
    def id_student(self):
        return self.__id_student
    def id_returnstud(self):
        return self.__id_student

    
    @property
    def id_assignment(self):
        return self.__id_assignment

    @property
    def price(self):
        return self.__price
    
    def __eq__(self, other):
        
        return type(self) == type(other) and self.id_assignment== other.id_assignment and self.id_student == other.id_student
    
    def __hash__(self):
        
        # valoare unica, folosit pentru adaugare in dictionarele din repository
        
        return hash(str(self.id_student) + str(self.id_assignment))