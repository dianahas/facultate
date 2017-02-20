'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

class Assignment:
    
    def __init__(self, id_assignment,description):
        
        self.__id_assignment = id_assignment
        self.__description =description
        
    @property
    def id_assignment(self):
        return self.__id_assignment
    
    @property
    def description(self):
        return self.__description
    
    def __str__(self):
        return "{0}. {1}".format(self.id_assignment, self.description)
    
    def __repr__(self):
        return str(self)
    
    def __eq__(self, other):
        return type(self) == type(other) and self.id_assignment == other.id_assignment
    
    def __hash__(self):
        
        # valoare unica, folosit pentru adaugare in dictionarele din repository
        
        return hash(self.id_assignment)
