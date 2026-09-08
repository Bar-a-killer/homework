from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib.units import cm
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, PageBreak, HRFlowable
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER, TA_LEFT, TA_JUSTIFY

# 註冊中文字體
pdfmetrics.registerFont(TTFont('NotoSans', '/tmp/NotoSansTC.ttf'))
pdfmetrics.registerFont(TTFont('NotoSansBold', '/tmp/NotoSansTC.ttf'))

# 頁面設定
doc = SimpleDocTemplate(
    '刑法概要學期報告_江其恩.pdf',
    pagesize=A4,
    rightMargin=2.5*cm,
    leftMargin=2.5*cm,
    topMargin=2.5*cm,
    bottomMargin=2.5*cm
)

W, H = A4

# 樣式定義
def style(name, font='NotoSans', size=12, leading=None, alignment=TA_LEFT,
          spaceBefore=0, spaceAfter=6, leftIndent=0, textColor=colors.black, bold=False):
    if leading is None:
        leading = size * 1.8
    f = 'NotoSansBold' if bold else font
    return ParagraphStyle(
        name,
        fontName=f,
        fontSize=size,
        leading=leading,
        alignment=alignment,
        spaceBefore=spaceBefore,
        spaceAfter=spaceAfter,
        leftIndent=leftIndent,
        textColor=textColor,
        wordWrap='CJK'
    )

s_title     = style('title',     size=20, alignment=TA_CENTER, spaceBefore=30, spaceAfter=10, bold=True)
s_subtitle  = style('subtitle',  size=13, alignment=TA_CENTER, spaceBefore=6,  spaceAfter=6)
s_cover_lbl = style('cover_lbl', size=13, alignment=TA_CENTER, spaceBefore=10, spaceAfter=4)
s_h1        = style('h1',        size=14, spaceBefore=18, spaceAfter=6, bold=True)
s_h2        = style('h2',        size=12, spaceBefore=12, spaceAfter=4, bold=True)
s_h3        = style('h3',        size=11, spaceBefore=8,  spaceAfter=3, bold=True)
s_body      = style('body',      size=11, spaceBefore=2,  spaceAfter=4, alignment=TA_JUSTIFY)
s_body_ind  = style('body_ind',  size=11, spaceBefore=2,  spaceAfter=4, alignment=TA_JUSTIFY, leftIndent=20)
s_quote     = style('quote',     size=10.5, spaceBefore=4, spaceAfter=4, alignment=TA_JUSTIFY,
                    leftIndent=30, textColor=colors.HexColor('#333333'))
s_toc       = style('toc',       size=11, spaceBefore=4,  spaceAfter=4)
s_center    = style('center',    size=11, alignment=TA_CENTER, spaceBefore=4, spaceAfter=4)

# 表格內專用樣式（置中與白色文字）
s_tbl_header = style('tbl_header', size=10, alignment=TA_CENTER, textColor=colors.white, bold=True, spaceAfter=0)
s_tbl_body   = style('tbl_body',   size=10, alignment=TA_CENTER, spaceAfter=0)

story = []

# ── 封面 ──────────────────────────────────────────────
story.append(Spacer(1, 3*cm))
story.append(Paragraph('刑法概要學期報告', s_title))
story.append(HRFlowable(width='80%', thickness=1.5, color=colors.HexColor('#444444'), spaceAfter=20))
story.append(Spacer(1, 1.2*cm))

cover_data = [
    ['課程名稱', '刑法概要'],
    ['指導老師', '周成瑜 博士'],
    ['報告主題', '乘機性交罪既、未遂之認定'],
    ['報告案號', '臺灣新北地院 105 年度侵訴字第 31 號判決（未遂）'],
    ['',         '臺灣高等法院 106 年度侵上訴字第 84 號判決（未遂）'],
    ['',         '最高法院 107 年度台上字第 678 號判決（駁回）'],
    ['系級姓名', '資工2A  江其恩  01372149'], 
    ['報告日期', '民國 115 年 04 月 08 日'], 
]

ct = Table(cover_data, colWidths=[3.5*cm, 11*cm])
ct.setStyle(TableStyle([
    ('FONTNAME',    (0,0), (-1,-1), 'NotoSans'),
    ('FONTNAME',    (0,0), (0,-1),  'NotoSansBold'),
    ('FONTSIZE',    (0,0), (-1,-1), 11.5),
    ('LEADING',     (0,0), (-1,-1), 22),
    ('VALIGN',      (0,0), (-1,-1), 'MIDDLE'),
    ('TOPPADDING',  (0,0), (-1,-1), 7),
    ('BOTTOMPADDING',(0,0),(-1,-1), 7),
    ('LEFTPADDING', (0,0), (-1,-1), 8),
    ('RIGHTPADDING',(0,0), (-1,-1), 8),
    ('ROWBACKGROUNDS',(0,0),(-1,-1),[colors.HexColor('#F5F5F5'), colors.white]),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#AAAAAA')),
    ('INNERGRID',   (0,0), (-1,-1), 0.3, colors.HexColor('#CCCCCC')),
    ('SPAN',        (0,3), (0,5)),  # 案號跨列
]))
story.append(ct)
story.append(PageBreak())

# ── 報告大綱 ──────────────────────────────────────────
story.append(Paragraph('報告大綱', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=8))
toc_items = [
    '一、罪章條文說明', 
    '二、事實經過', 
    '三、爭議點', 
    '四、各該案號判決理由分析', 
    '五、心得（是否認同判決、如何預防避免）', 
]
for item in toc_items:
    story.append(Paragraph(item, s_toc))
story.append(PageBreak())

# ── 一、罪章條文說明 ─────────────────────────────────
story.append(Paragraph('一、罪章條文說明', s_h1))
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('（一）乘機性交罪之法條依據', s_h2))
story.append(Paragraph(
    '本案所涉主要法條為中華民國刑法第225條（乘機性交猥褻罪），條文內容如下：', s_body))

# 修正：將表格內的純字串全部用 Paragraph 包裹，使其能依欄寬自動換行
quote_data = [
    [Paragraph('<b>第一項</b>', s_body), Paragraph('對於男女，利用其精神、身體障礙、心智缺陷或其他相類之情形，不能或不知抗拒而為性交者，處三年以上十年以下有期徒刑。', s_body)],
    [Paragraph('<b>第二項</b>', s_body), Paragraph('對於男女，利用其精神、身體障礙、心智缺陷或其他相類之情形，不能或不知抗拒而為猥褻之行為者，處六月以上五年以下有期徒刑。', s_body)],
    [Paragraph('<b>第三項</b>', s_body), Paragraph('第一項之未遂犯罰之。', s_body)],
]

# 稍微調整配寬，2.5cm + 13.5cm = 16cm（剛好完美貼齊你的頁面邊界）
qt = Table(quote_data, colWidths=[2.5*cm, 13.5*cm])
qt.setStyle(TableStyle([
    ('VALIGN',       (0,0), (-1,-1), 'TOP'),
    ('TOPPADDING',   (0,0), (-1,-1), 8),
    ('BOTTOMPADDING',(0,0), (-1,-1), 8),
    ('LEFTPADDING',  (0,0), (-1,-1), 8),
    ('RIGHTPADDING', (0,0), (-1,-1), 8),
    ('BACKGROUND',   (0,0), (-1,-1), colors.HexColor('#F9F9F9')),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#AAAAAA')),
    ('INNERGRID',    (0,0), (-1,-1), 0.3, colors.HexColor('#DDDDDD')),
]))
story.append(qt)
story.append(Spacer(1, 8))

story.append(Paragraph('（二）「性交」之定義', s_h2)) 
story.append(Paragraph(
    '依刑法第10條第5項規定，所謂「性交」，係指非基於正當目的所為之下列性侵入行為：', s_body)) 
story.append(Paragraph('1. 以性器進入他人之性器、肛門或口腔，或使之接合之行為。', s_body_ind)) 
story.append(Paragraph('2. 以性器以外之其他身體部位或器物進入他人之性器、肛門，或使之接合之行為。', s_body_ind)) 

story.append(Paragraph('（三）本罪之構成要件分析', s_h2)) 
story.append(Paragraph('【客觀構成要件】', s_h3)) 
story.append(Paragraph(
    '1. 行為主體：任何人均可構成本罪，男女皆可為行為人，男女皆可為被害人，性別中立。', s_body)) 
story.append(Paragraph(
    '2. 被害人之狀態：被害人須因精神障礙、身體障礙、心智缺陷或其他相類情形（如酒醉昏睡、藥物影響），而處於「不能或不知抗拒」之狀態。所謂「相類情形」，依最高法院見解，係指被害人雖非精神、身體或心智障礙，但受性交時因昏暈、酣眠、泥醉等相類似情形，致無同意性交之理解，或無抗拒性交之能力者而言（最高法院96年度台上字第4376號判決意旨）。', s_body)) 
story.append(Paragraph(
    '3. 行為人之行為：行為人須「利用」上述不能或不知抗拒之狀態而為性交行為。此「利用」係指行為人並非自行製造被害人之無助狀態，而係乘機加以利用，此點為與強制性交罪之區別關鍵所在。', s_body)) 

story.append(Paragraph('【主觀構成要件】', s_h3)) 
story.append(Paragraph(
    '行為人須具有乘機性交之故意，即明知被害人處於不能或不知抗拒之狀態，仍有意加以利用而實行性交行為。', s_body)) 

story.append(Paragraph('【既遂與未遂之區分】', s_h3)) 
story.append(Paragraph(
    '依刑法第10條第5項及實務採行之「接合說」，性交既遂之認定，僅須性器或性器以外之其他身體部位進入他人性器，或使之接合，即屬既遂，並非以插入陰道為必要。最高法院111年度台上字第527號判決進一步闡明，女性外陰部生殖器官包括陰阜、大陰唇、小陰唇、陰蒂、前庭、陰道口、處女膜外側，凡以性器或性器以外之其他身體部位或器物進入大陰唇內側之性器之性侵入行為，均屬刑法第10條第5項所指之性交，並非以插入陰道深部為必要。', s_body)) 
story.append(Paragraph(
    '若行為人已著手實行性交行為，但因外力介入或其他原因而未達到上述「接合」程度，則成立未遂犯，依刑法第25條第2項規定，得按既遂犯之刑度減輕其刑。', s_body)) 

story.append(Paragraph('（四）本罪與強制性交罪之比較', s_h2)) 
story.append(Paragraph(
    '本罪（刑法第225條）與強制性交罪（刑法第221條）之最大差異，在於被害人陷入不能或不知抗拒之狀態的原因：', s_body)) 

# 修正：將表格內部文字封裝進 Paragraph 並改用 <br/> 換行，確保 ReportLab 能正確排版
compare_data = [
    [Paragraph('比較項目', s_tbl_header), Paragraph('乘機性交罪（第225條）', s_tbl_header), Paragraph('強制性交罪（第221條）', s_tbl_header)], 
    [Paragraph('不能抗拒狀態之來源', s_tbl_body), Paragraph('被害人本身既有狀態<br/>（酒醉、障礙等）', s_tbl_body), Paragraph('行為人以強暴、脅迫<br/>等手段製造', s_tbl_body)], 
    [Paragraph('行為人之手段', s_tbl_body), Paragraph('僅利用既有狀態', s_tbl_body), Paragraph('主動施以強制手段', s_tbl_body)], 
    [Paragraph('法定刑', s_tbl_body), Paragraph('3年以上、10年以下<br/>有期徒刑', s_tbl_body), Paragraph('3年以上、10年以下<br/>有期徒刑', s_tbl_body)], 
]
cmp_t = Table(compare_data, colWidths=[4*cm, 5*cm, 5*cm])
cmp_t.setStyle(TableStyle([
    ('VALIGN',        (0,0), (-1,-1), 'MIDDLE'),
    ('TOPPADDING',   (0,0), (-1,-1), 8),
    ('BOTTOMPADDING',(0,0), (-1,-1), 8),
    ('BACKGROUND',   (0,0), (-1,0),  colors.HexColor('#3A3A3A')),
    ('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.HexColor('#F0F0F0'), colors.white]),
    ('BOX',          (0,0), (-1,-1), 0.5, colors.HexColor('#888888')),
    ('INNERGRID',    (0,0), (-1,-1), 0.3, colors.HexColor('#BBBBBB')),
]))
story.append(cmp_t)
story.append(PageBreak())

# ── 二、事實經過 ─────────────────────────────────────
story.append(Paragraph('二、事實經過', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('被告：王凱民', s_body)) 
story.append(Paragraph('被害人：A女（依性侵害犯罪防治法第12條規定，姓名依法遮蔽）', s_body)) 
story.append(Spacer(1, 6))
story.append(Paragraph(
    '民國104年6月27日晚間，被告王凱民與A女等一群人在某大學校區內聚會飲酒。至同年月28日凌晨3時許，A女已因大量飲酒而意識不清、全身癱軟無力，終至昏睡，處於類似精神障礙、不能及不知抗拒之狀態。', s_body)) 
story.append(Paragraph(
    '王凱民見A女酒醉昏睡，起乘機性交之犯意，利用A女不能及不知抗拒之機會，對A女著手實行性交行為。然而，就在王凱民實行性交行為之際，被A女的男友B男等人發現並即時阻止，導致性交行為未能完成（未遂）。', s_body)) 
story.append(Paragraph(
    '事後，A女被送往亞東醫院救治。警方採集A女外陰部棉棒送驗，鑑定結果在A女外陰部棉棒檢出一男性Y染色體DNA-STR型別，與王凱民之Y染色體DNA-STR型別相符。然而，在A女陰道深部及外陰部以酸性磷酸酵素法檢測，結果均呈弱陽性反應，以顯微鏡及前列腺抗原檢測法確認，並未發現精子細胞或精液反應，A女性器內亦未檢出任何王凱民之DNA。', s_body)) 
story.append(PageBreak())

# ── 三、爭議點 ───────────────────────────────────────
story.append(Paragraph('三、爭議點', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('爭議一：乘機性交罪既遂或未遂之認定標準為何？', s_h2)) 
story.append(Paragraph(
    '本案最關鍵之爭議在於：王凱民之行為究竟構成乘機性交既遂，還是乘機性交未遂？', s_body)) 
story.append(Paragraph(
    '【既遂說】：從A女外陰部採得與王凱民相符之Y染色體DNA型別，足以證明王凱民之性器已與A女性器有所接觸，依「接合說」，應成立既遂。', s_body_ind)) 
story.append(Paragraph(
    '【未遂說】：雖在A女外陰部採得DNA，然無法確認係精子細胞；A女性器內未檢出王凱民之DNA；以酸性磷酸酵素法及前列腺抗原法均未在A女陰道深部或外陰部發現精液。在此情況下，尚不足以遽認王凱民有以陰莖插入A女陰道而性交既遂，故應成立未遂。', s_body_ind)) 

story.append(Paragraph('爭議二：A女是否確實處於「不能或不知抗拒」之狀態？', s_h2)) 
story.append(Paragraph(
    '王凱民方於訴訟中提出抗辯，否認A女有酒醉到不能或不知抗拒之程度，亦否認本身有為性交行為之犯意。此爭議點涉及酒醉程度之認定，以及被害人陳述之可信性。', s_body)) 
story.append(PageBreak())

# ── 四、各該案號判決理由分析 ─────────────────────────
story.append(Paragraph('四、各該案號判決理由分析', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

# 一審
story.append(Paragraph('（一）第一審：臺灣新北地院 105 年度侵訴字第 31 號判決', s_h2)) 
story.append(Paragraph('判決結果：論王凱民以乘機性交未遂罪，依刑法第25條第2項規定減輕其刑後，處有期徒刑3年6月。', s_body)) 
story.append(Paragraph('判決理由：', s_h3)) 
story.append(Paragraph(
    '1. 被害人之不能抗拒狀態確立：A女於案發凌晨時分，已因酒醉意識不清、全身癱軟無力，終至昏睡，處於類似精神障礙不能及不知抗拒之狀態。此有A女、B男等多名證人之證詞，以及新北市政府消防局對A女之救護紀錄表暨亞東醫院函文在卷可稽。', s_body)) 
story.append(Paragraph(
    '2. 王凱民犯意確認：王凱民係基於乘機性交之犯意，利用A女酒醉昏睡之狀態，著手對A女為性交行為，此有A女等多名證人之證詞及刑事警察局之DNA鑑定書可資佐證（A女外陰部棉棒檢出與王凱民Y染色體DNA-STR型別相符之組織）。', s_body)) 
story.append(Paragraph(
    '3. 未遂之認定：法院審酌DNA鑑定結果，認定僅在A女外陰部採得DNA，惟不能確認係精子細胞；A女陰道深部及外陰部以酸性磷酸酵素法暨前列腺抗原法均無精液或精子細胞之反應；A女性器內亦未檢出王凱民之DNA。在此等鑑定結論下，「尚難遽認王凱民有以其陰莖插入A女陰道而性交既遂之事實」，故認定王凱民有乘機性交未遂之犯行。', s_body)) 
story.append(Paragraph('4. 否認抗辯：王凱民否認犯罪及所辯各節，均不足採信，法院一一指駁說明。', s_body)) 

# 二審
story.append(Paragraph('（二）第二審：臺灣高等法院 106 年度侵上訴字第 84 號判決', s_h2)) 
story.append(Paragraph('判決結果：駁回王凱民之上訴，維持第一審論以乘機性交未遂罪、有期徒刑3年6月之判決。', s_body)) 
story.append(Paragraph('判決理由：', s_h3)) 
story.append(Paragraph(
    '第二審高等法院認為，第一審判決所為之認定，有充分之事實依據，且論斷俱與卷內資料相符，並無明顯違背證據法則之情形。具體而言：', s_body)) 
story.append(Paragraph(
    '1. 認同一審對被害人狀態之認定：A女酒醉不能及不知抗拒之狀態，業有多位目睹者之證詞及消防救護紀錄、醫療文件佐證，事實明確。', s_body)) 
story.append(Paragraph(
    '2. 認同未遂之認定：依DNA鑑定結果，僅在A女外陰部採得相符型別之組織，然無法確認係精子細胞，A女性器深部及外陰部均無精液反應，A女性器內亦未檢出王凱民DNA，故不能遽認既遂，維持未遂之認定。', s_body)) 
story.append(Paragraph(
    '3. 量刑適當：一審依刑法第25條第2項減輕後，量處有期徒刑3年6月，未逾越法定刑範圍，亦未違反公平、比例及罪刑相當原則，量刑適當。', s_body)) 

# 三審
story.append(Paragraph('（三）第三審：最高法院 107 年度台上字第 678 號判決', s_h2)) 
story.append(Paragraph('判決結果：以上訴不合法律上之程式為由，駁回王凱民之上訴，全案確定。', s_body)) 
story.append(Paragraph('判決理由：', s_h3)) 
story.append(Paragraph(
    '最高法院於民國107年3月22日作成本號判決，其駁回理由除程序面外，更就實體面詳加說明，確認二審判決之正確性：', s_body)) 
story.append(Paragraph('1. 程序面：王凱民之上訴不合法律上之程式，依法予以駁回。', s_body)) 
story.append(Paragraph('2. 實體面之確認：最高法院肯認二審判決所援引之各項事實認定及法律論斷，並確立以下重要法律原則：', s_body)) 
story.append(Paragraph(
    '甲、乘機性交罪之成立，以被害人處於「不能或不知抗拒」之狀態為必要，此狀態之形成，需有充分之客觀事證（如救護紀錄、醫療文件、目擊證人等）支持，方得確認。', s_body_ind)) 
story.append(Paragraph(
    '乙、性交既遂與未遂之區分，依「接合說」，以性器是否進入或接合他人之性器為斷，惟在DNA鑑定僅於外陰部採得，且無法確認係精子細胞，性器深部亦無精液反應之情況下，尚不能以此遽認插入陰道之性交既遂事實，從而應論以未遂。', s_body_ind)) 
story.append(Paragraph(
    '丙、未遂犯之處理：依刑法第25條第2項規定，未遂犯之刑度得按既遂犯之刑減輕之，本案一、二審均依此規定處有期徒刑3年6月，最高法院亦確認量刑合法適當。', s_body_ind)) 
story.append(PageBreak())

# ── 五、心得 ─────────────────────────────────────────
story.append(Paragraph('五、心得', s_h1)) 
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=6))

story.append(Paragraph('（一）對本系列判決之評析', s_h2)) 
story.append(Paragraph(
    '本系列三個判決，自一審地院、二審高院至三審最高法院，均一致認定本案王凱民成立乘機性交未遂罪，整體而言，筆者認同此結論，理由如下：', s_body)) 

story.append(Paragraph('1. 被害人不能抗拒狀態之認定合理', s_h3)) 
story.append(Paragraph(
    '本案中，A女酒醉昏睡、全身癱軟之事實，有多名在場目擊者之一致證詞，及消防救護紀錄、醫院文件等客觀書證相互印證，足以排除合理懷疑，確認A女當時已處於不能及不知抗拒之狀態，符合刑法第225條第1項所定「相類情形」之要件。', s_body)) 

story.append(Paragraph('2. 未遂認定之謹慎態度值得肯定', s_h3)) 
story.append(Paragraph(
    '就既遂與未遂之認定，法院在欠缺精液、精子細胞之明確鑑定依據的情況下，並未輕率認定既遂，而是依「罪疑唯輕」之刑事訴訟基本原則，以「尚難遽認」之措辭，審慎認定未遂，展現司法應有的謹慎態度，保障了被告不受過度入罪的基本權利。', s_body)) 

story.append(Paragraph('3. 性交定義之實務操作有待釐清', s_h3)) 
story.append(Paragraph(
    '本案發生時（民國104年）及三審判決作成時（民國107年），實務上對於性交既遂之「接合說」雖已確立，但對於「進入大陰唇內側即屬既遂」之見解，係在後來（最高法院111年度台上字第527號判決）方更明確地加以闡釋。本案判決作成時，DNA僅採得於外陰部，且無法確認係精子細胞，法院選擇不認定既遂，在當時的法律解釋框架下是合理謹慎的。', s_body)) 

story.append(Paragraph('（二）如何預防、避免類似事件的發生', s_h2)) 
story.append(Paragraph(
    '本案呈現的是利用他人酒醉昏睡、乘機性侵的犯罪型態，對個人性自主權及身體安全造成嚴重侵害。預防此類事件，可從以下幾個層面著手：', s_body)) 

story.append(Paragraph('【個人層面】', s_h3)) 
story.append(Paragraph(
    '1. 飲酒時應掌握自身酒量，避免飲酒過量以致失去自我保護能力，聚會時應與可信任的朋友相互照應。', s_body)) 
story.append(Paragraph('2. 不單獨與不熟識的人留在封閉空間，並注意周遭環境的安全。', s_body)) 
story.append(Paragraph(
    '3. 提升法律意識，認識到「對方沒有明確表示同意」並非自動授予同意，且酒醉失去意識者在法律上完全不具備同意性交之能力。', s_body)) 

story.append(Paragraph('【社會層面】', s_h3)) 
story.append(Paragraph(
    '1. 強化性別平等教育，糾正「對方喝酒就是默許」等錯誤觀念，建立尊重他人性自主意願的文化。', s_body)) 
story.append(Paragraph('2. 鼓勵旁觀者介入（如本案之B男及時阻止），建立守望相助的社群意識。', s_body)) 

story.append(Paragraph('【法律制度層面】', s_h3)) 
story.append(Paragraph(
    '1. 刑法第225條第3項明定未遂犯亦須處罰，充分發揮刑罰的一般預防及特別預防功能，值得肯定。', s_body)) 
story.append(Paragraph(
    '2. 司法機關對於被害人之陳述及相關證據，應保持專業、敏感且不帶偏見之態度，保障被害人在訴訟程序中受到公正對待，降低其再次受創之風險。', s_body)) 

story.append(Spacer(1, 1*cm))
story.append(HRFlowable(width='100%', thickness=0.5, color=colors.HexColor('#AAAAAA'), spaceAfter=8))
story.append(Paragraph('參考資料', s_h2)) 
refs = [
    '中華民國刑法第10條、第25條、第221條、第225條', 
    '臺灣新北地方法院105年度侵訴字第31號刑事判決', 
    '臺灣高等法院106年度侵上訴字第84號刑事判決', 
    '最高法院107年度台上字第678號刑事判決暨新聞稿（司法院法學資料檢索系統）', 
    '最高法院96年度台上字第4376號判決', 
    '最高法院101年度台上字第2012號判決', 
    '最高法院111年度台上字第527號判決', 
]
for r in refs:
    story.append(Paragraph(f'• {r}', s_body))

doc.build(story)
print('PDF生成完成')