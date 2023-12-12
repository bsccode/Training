text = "X-DSPAM-Confidence:    0.8475"
posi = text.find(":")
num = float(text[-6:len(text)])
print(num)