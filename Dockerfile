FROM python:3.10-slim

#Install dependencies
RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    libusb-1.0-0\
    && pip install platformio \
    && apt-get clean 


#Create a user
RUN useradd -m -s /bin/bash devuser
USER devuser
# Set up the project directory
WORKDIR /home/devuser/project

CMD ["pio","run"]
