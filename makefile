CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = lms
SRCS = main.cpp student.cpp course.cpp club.cpp department.cpp utility.cpp user.cpp enrollment.cpp assignment.cpp event.cpp faculty.cpp project.cpp grade.cpp libraryresources.cpp attendance.cpp feedback.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run