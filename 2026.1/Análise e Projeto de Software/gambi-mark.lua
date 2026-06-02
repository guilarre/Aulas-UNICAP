function Span(el)
  if el.classes:includes('mark') and FORMAT == 'typst' then
    table.insert(el.content, 1, pandoc.RawInline('typst', '#highlight['))
    table.insert(el.content, pandoc.RawInline('typst', ']'))
    return el.content
  end
end
