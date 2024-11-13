import React, { useState } from 'react'

interface Logo {
    url: string
    alt: string
}

interface MediaScrollProps {
    className?: string
    pauseOnHover?: boolean
    speed?: number
    logos?: Logo[]
}

const defaultLogos: Logo[] = [
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/cosmopolitan.svg', alt: 'Cosmopolitan' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/vogue.svg', alt: 'Vogue' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/elle.svg', alt: 'Elle' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/marie-claire.svg', alt: 'marie claire' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/instyle.svg', alt: 'InStyle' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/grazia.svg', alt: 'Grazia' },
    { url: 'https://web.archive.org/web/20240921123053im_/https://cocosolis.com/bg/wp-content/uploads/forbes.svg', alt: 'Forbes' },
    { url: 'https://web.archive.org/web/20240921123054im_/https://cocosolis.com/bg/wp-content/uploads/vanityfair.svg', alt: 'Vanity Fair' },
]

const cn = (...classes: (string | boolean | undefined)[]) => {
    return classes.filter(Boolean).join(' ')
}

export default function MediaScroll({
    className,
    pauseOnHover = true,
    speed = 30,
    logos = defaultLogos
}: MediaScrollProps) {
    const [isHovered, setIsHovered] = useState(false)

    const scrollContent = (
        <>
        <span className="text-sm text-pinkish text-white" aria-label="Media">МЕДИИТЕ ГОВОРЯТ ЗА НАС</span>
        {logos.map((logo, idx) => (
            <img
            key={`${logo.alt}-${idx}`}
            src={logo.url}
            alt={logo.alt}
            className="h-4 object-contain w-screen max-w-[100px]"
            />
        ))}
        </>
    )

    return (
        <div 
        className={cn(
            "w-screen overflow-hidden bg-background relative mt-4 bg-[#816c65]",
            className
        )}
        onMouseEnter={() => pauseOnHover && setIsHovered(true)}
        onMouseLeave={() => pauseOnHover && setIsHovered(false)}
        >
            <div
                className={cn(
                "flex items-center gap-8 p-3",
                "animate-marquee",
                isHovered && "animation-paused"
                )}
                style={{
                '--marquee-duration': `${speed}s`,
                width: '200%',
                } as React.CSSProperties}
            >
                {scrollContent}
                {scrollContent}
            </div>
        </div>
    )
}
