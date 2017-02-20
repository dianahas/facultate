'''
Created on Nov 25, 2015

@author: Daniel
'''
'''
Created on Nov 13, 2015

@author: Vlad
'''
from Domain.Rental import Rental
from Domain.RentalDTO import RentalDTO

class RentalController:
    
    def __init__(self, student_repo, assignment_repo, rental_repo):
        
        self.__student_repo = student_repo
        self.__assignment_repo = assignment_repo
        self.__rental_repo = rental_repo
        
    def add(self, id_student, id_assignment, price):
        
        student = self.__student_repo.find_by_id(id_student)
        if student is None:
            raise ValueError("No such student exists!")
        
        assignment = self.__assignment_repo.find_by_id(id_assignment)
        if assignment is None:
            raise ValueError("No such assignment exists!")
        
        rental = Rental(student, assignment, price)
        
        # TODO: validate rental (client and car can be passed to the validator and exceptions on them raised there)
        
        self.__rental_repo.add(RentalDTO(rental.student.id_student, rental.assignment.id_assignment, rental.price))

        
    def get_all(self):
        
        all_dto = self.__rental_repo.get_all_DTO()
        
        all_rentals = [Rental(self.__student_repo.find_by_id(dto.id_student), self.__assignment_repo.find_by_id(dto.id_assignment), dto.price) for dto in all_dto]
        
        return all_rentals

    def delete(self, id_student, id_assignment):
        
        self.__rental_repo.delete(id_student, id_assignment)
        
    def delete_by_student(self, id_student):
        
        self.__rental_repo.delete_by_student(id_student)
        
    def delete_by_assignment(self, id_assignment):
        
        self.__rental_repo.delete_by_assignment(id_assignment)
    def update_by_student(self,id_student):
        
    
        for i in range(0,len(self.__rental_repo.get_all_DTO)):
            oldstudent=self.__rental_repo.get_all_DTO[i].id_returnstud()
            
            