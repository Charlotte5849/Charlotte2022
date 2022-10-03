from NameList import NameList
class student(TMU):
  def __init__(self, name, number):
        self.name = name
        self.number = number

  def show(self):
        print("name:", self.name)
        print("number:", self.number)
charlotte=student("CharlotteChen","B812108030")
charlotte.show()
