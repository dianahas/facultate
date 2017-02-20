'''
Created on Nov 25, 2015

@author: Daniel
'''

from Repositories.Repository import GenericRepository

class StudentRepository(GenericRepository):
    
    def __init__(self):
        
        super().__init__()
    
    def find_by_id(self, id_student):

        for obj in self.get_all():
            if obj.id_student == id_student:
                return obj
        
        return None
    
    def delete(self, id_student):
        
        for obj in self._storage:
            if obj.id_student == id_student:
                self._storage.remove(obj)
                return
    