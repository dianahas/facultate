'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''

from Repositories.Repository import GenericRepository
from Domain.RentalDTO import RentalDTO

class RentalRepository(GenericRepository):
    
    def __init__(self):
        
        super().__init__()
        
    def find_by_id(self, id_student, id_assignment):
        
        for obj in self.get_all():
            if obj.id_student == id_student and obj.id_assignment == id_assignment:
                return obj
        
        return None
    def find_by_studentid(self, id_student):
        list=[]
        for obj in self.get_all():
            if obj.id_student == id_student:
                list.append(obj)
        
        return 0
        
    def find_by_student(self, id_student):
        return [RentalDTO(obj.id_student, obj.id_assignment, obj.price) for obj in self.get_all() if obj.id_student == id_student]

    def find_by_assignment(self, id_assignment):
        return [RentalDTO(obj.id_student, obj.id_assignment, obj.price) for obj in self.get_all() if obj.id_assignment == id_assignment]
    
    def add(self, rental_dto):
        
        if self.find_by_id(rental_dto.id_student, rental_dto.id_assignment) is not None:
            raise KeyError("Rental already exists!")
    
        self._storage.append(rental_dto)
        
    def __del(self, condition):
        
        deleted = [rental for rental in self._storage if condition(rental)]
        self._storage = [rental for rental in self._storage if rental not in deleted]
        
        return deleted
    
    def delete(self, id_student, id_assignment):
        
        deleted = self.__del(lambda x: x.id_student == id_student and x.id_assignment == id_assignment)
        
        if deleted == []:
            raise KeyError("The assignment is not selected for the student!")
    
        return deleted
    
    def delete_by_student(self, id_student):
    
        return self.__del(lambda x: x.id_student == id_student)
    
    def delete_by_assignment(self, id_assignment):
    
        return self.__del(lambda x: x.id_assignment == id_assignment)

    def get_all_DTO(self):
        
        return [RentalDTO(obj.id_student, obj.id_assignment, obj.price) for obj in self.get_all()]