'''
Created on Nov 25, 2015

@author: Teo

'''
from Repositories.Repository import GenericRepository

class AssignmentRepository(GenericRepository):
    
    def __init__(self):
        
        super().__init__()
    
    def find_by_id(self, id_assignment):

        for obj in self._storage:
            if obj.id_assignment == id_assignment:
                return obj
            
        return None
    
    def delete(self, id_assignment):
        
        for obj in self._storage:
            if obj.id_assignment == id_assignment:
                self._storage.remove(obj)
                return obj
        
        raise KeyError("Object does not exist!")
        
    def add(self, assignment):
        
        if assignment in self._storage:
            raise KeyError("That assignment already exists!")
        
        self._storage.append(assignment)