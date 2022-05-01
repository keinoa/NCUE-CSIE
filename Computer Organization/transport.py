import comtypes.client
import os
def ppt_to_pdf(origin, transport):
    #設定路徑
    input_file_path=os.path.abspath(origin)
    output_file_path=os.path.abspath(transport)
    #建立PDF
    powerpoint=comtypes.client.CreateObject("Powerpoint.Application")
    powerpoint.Visible=1
    slides=powerpoint.Presentations.Open(input_file_path)
    #儲存PDF
    slides.SaveAs(output_file_path,32)
    slides.Close()

ppt_to_pdf("Ch07_Multicores Multiprocessors and Clusters.ppt", "Ch07_Multicores Multiprocessors and Clusters.pdf")
# for i in range(2,21):
#     if i < 10:
#         ppt_to_pdf("sp0" + str(i) + ".ppt", "sp0" + str(i) + ".pdf")
#         # print("sp0" + str(i) + ".ppt")
#     else:   
#         ppt_to_pdf("sp"  + str(i) + ".ppt", "sp" + str(i) + ".pdf")
#         # print("sp"  + str(i) + ".ppt")