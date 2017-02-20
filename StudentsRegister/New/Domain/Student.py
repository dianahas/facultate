'''
Created on Nov 13, 2015

@author: Vlad
'''

class Student:
    
    def __init__(self, id_student, name,group):
        
        self.__id_student = id_student
        self.__name = name
        self.__group = group
        
    @property
    def id_student(self):
        return self.__id_student
    
    @property
    def name(self):
        return self.__name
    @property
    def group(self):
        return self.__group
    
    def __str__(self):
        return "{0}. {1}. {2}".format(self.id_student, self.name, self.group)

    def __repr__(self):
        return str(self)
    
    def __eq__(self, other):
        return type(self) == type(other) and self.id_student == other.id_student
    
    def __hash__(self):
        
        # valoare unica, folosit pentru adaugare in dictionarele din repository
        
        return hash(self.id_student)